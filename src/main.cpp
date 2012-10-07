#include "problem.hpp"

#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <boost/multi_array.hpp>


unsigned nbSites;
unsigned nbStores;
std::vector<short> sites;
std::vector<unsigned> capacities;
std::vector<std::pair<int, int>> coordinates;
boost::multi_array<short, 2> distances;

void readFile(char* fileName)
{
    std::ifstream file(fileName);

    if (file) {
        std::string line;
        std::vector<std::string> strs;

        // The first line
        std::getline(file, line);
        boost::split(strs, line, boost::is_any_of(" "));

        nbSites = atoi(strs.at(0).c_str());
        nbStores = atoi(strs.at(1).c_str());

        // The rest of the file
        while (std::getline(file, line)) {
            boost::split(strs, line, boost::is_any_of(" "));

            sites.push_back(0);
            coordinates.push_back(std::make_pair(atoi(strs.at(1).c_str()), atoi(strs.at(2).c_str())));
            capacities.push_back(atoi(strs.at(3).c_str()));
        }

        // Set the distances between sites
        distances.resize(boost::extents[nbSites][nbSites]);
        for (unsigned i = 0; i < nbSites; ++i) {
            for (unsigned j = 0; j < nbSites; ++j) {
                // if (i != j) {
                    int dist = std::abs(coordinates.at(i).first - coordinates.at(j).first) +
                        std::abs(coordinates.at(i).second - coordinates.at(j).second);
                    distances[i][j] = (dist <= 50) ? 1 : 0;
                    // std::cout << distances[i][j] << " ";
                // }
            }
            // std::cout << std::endl;
        }

        file.close();
    }
}


void writeFile(const std::vector<int>& v)
{
    std::ofstream file("output.txt");

    for (int i : v)
        file << i << " ";

    file.close();
}

int main(int argc, char** argv)
{
    if (argc != 2)
        return 1;

    readFile(argv[1]);

    Problem pb("pb");
    pb.setOptimization(Problem::MAXIMIZE);

    // Constraints
    Constraint p(pb);

    p.set_name("p");
    p.set_bounds(GLP_FX, nbStores, nbStores);

    // Variables
    std::vector<Variable> variables;

    // That works
    for (unsigned i = 1; i <= nbSites; ++i) {
        Variable v(pb);
        std::stringstream ss;
        ss << i;

        std::string name = "B" + ss.str();

        v.set_name(name);
        v.set_bounds(GLP_DB, 0.0, 1.0);
        v.set_coef(capacities.at(i - 1));

        variables.push_back(v);
        pb.setConstraintsValues(p, v, 1.0);
    }

    std::vector<Constraint> constraints;

    // That doesn't quite work
    for (unsigned i = 0; i < nbSites; ++i) {
        for (unsigned j = 0; j < nbSites; ++j) {
            if (i < j) {
                Constraint c(pb);

                if (distances[i][j] == 0) {
                    c.set_bounds(GLP_UP, 0.0, 1.0);
                }
                else {
                    c.set_bounds(GLP_UP, 0.0, 2.0);
                }

                pb.setConstraintsValues(c, i + 1, 1.0);
                pb.setConstraintsValues(c, j + 1, 1.0);

                constraints.push_back(c);
            }
        }
    }
    std::cout << constraints.size() << std::endl;


    writeFile(pb.solve());

    return 0;
}
