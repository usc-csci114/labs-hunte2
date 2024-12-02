#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

map<char, set<char> > searchGraph(const string& filename, set<char>& vertices){
    map<char, set<char> > graph;
    ifstream file(filename);
    string line;

    while(getline(file, line)){
        stringstream ss(line);
        char vertex;
        ss >> vertex;
        vertices.insert(vertex);
        string neighbor;
        while (ss >> neighbor){
            if(neighbor != "0"){
                graph[vertex].insert(neighbor[0]);
            }
        }
    }
    return graph;
}





vector<pair<char, int> > bfs(const map<char, set<char> >& graph, char start){
    vector<pair<char, int> > found; //pair obj used to easily store them as theyre found
    queue<char> neighNeigh;
    map<char, int> loc;
    map<char, bool> visited;

    neighNeigh.push(start);
    visited[start] = true;
    loc[start] = 0;
    while(!neighNeigh.empty()){
        char current = neighNeigh.front();
        neighNeigh.pop();
        found.push_back(make_pair(current, loc[current])); //creates new pair 

        for(char neighbor : graph.at(current)){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                loc[neighbor] = loc[current] + 1;
                neighNeigh.push(neighbor);
            }
        }
    }
    return found;
}






int main(int argc, char* argv[]){

    string filename = argv[1];
    set<char> vertices;
    map<char, set<char> > graph = searchGraph(filename, vertices);

    cout << "Processed file " << filename << ". Found " << vertices.size() << " vertexs: ";
    for(auto it = vertices.begin(); it != vertices.end(); ++it) {
        if(it != vertices.begin()){
            cout << ", ";
        }
        cout << *it;
    }
    cout << endl << endl;

    //part2
    string input;
    while(true){
        cout << "Enter starting vertex for BFS (q to exit): ";
        getline(cin, input);

        if(input == "q" || input == "Q"){
            break;
        }

        char start = input[0];
        vector<pair<char, int> > result = bfs(graph, start);

        cout << "BFS starting at " << start << ": ";
        for(size_t i = 0; i < result.size(); ++i){
            if (i > 0) cout << ", ";
            cout << result[i].first << ":" << result[i].second;
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}
