// An Iterative C++ program to do DFS traversal from
// a given source vertex. DFS(int s) traverses vertices
// reachable from s.
#include <iostream>
#include <bits/stdc++.h>
#include <string> 
#include <chrono>
using namespace std;
using namespace std::chrono;
 
// This class represents a directed graph using adjacency
// list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // adjacency lists
public:
  int contador = 0;
  int operaciones = 0;
  string resultado;

  Graph(int V);  // Constructor
  void AddEdge(int v, int w); // to add an edge to graph
  void DFS(int s, string num);  // prints all vertices in DFS manner
    
  //Encrypt function
  void Encrypt(int v, string num);

  //Operaciones counter funct
  void ResOperaciones();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::AddEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
// prints all not yet visited vertices reachable from s
void Graph::DFS(int s, string num)
{
    // Initially mark all verices as not visited
    vector<bool> visited(V, false);
 
    // Create a stack for DFS
    stack<int> stack;
 
    // Push the current source node.
    stack.push(s);
 
    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        s = stack.top();
        stack.pop();
 
        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[s])
        {
            //cout << s << " ";
            visited[s] = true;
            Encrypt(s, num);
        }
 
        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it
        // to the stack.
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i){
          if (!visited[*i]){
            stack.push(*i);
          }         
        }
    }
}

void Graph::Encrypt(int v, string num){
  char ctemp = num[contador];
  string stemp{ctemp};
  int realnum;

  try {
	  realnum = stoi(stemp);
  } 

  catch (...){
    return;
  }

  switch(v){
    case 0:
      if(realnum == 1){
        resultado.append("A"); contador++; operaciones++;
      }
      return;

    case 1:
      if(realnum == 2){
        resultado.append("B"); contador++; operaciones++;
      }
      return;

    case 2:
      if(realnum == 5){
        resultado.append("C"); contador++; operaciones++;
      }
      return;

    case 3:
      if(realnum == 6){
        resultado.append("D"); contador++; operaciones++;
      }
      return;

    case 4:
      if(realnum == 3){
        resultado.append("E"); contador++; operaciones++;
      }
      return;

    case 5:
      if(realnum == 4){
        resultado.append("F"); contador++; operaciones++;
      }
      return;

    case 6:
      if(realnum == 1){
        resultado.append("F"); contador++; operaciones++;
      }
      return;

    case 7:
      if(realnum == 2){
        resultado.append("H"); contador++; operaciones++;
      }
      return;

    case 8:
      if(realnum == 6){
        resultado.append("I"); contador++; operaciones++;
      }
      return;

    case 9:
      if(realnum == 3){
        resultado.append("J"); contador++; operaciones++;
      }
      return;

    case 10:
      if(realnum == 2){
        resultado.append("L"); contador++; operaciones++;
      }
      return;

    case 11:
      if(realnum == 6){
        resultado.append("M"); contador++; operaciones++;
      }
      return;

    case 12:
      if(realnum == 4){
        resultado.append("K"); contador++; operaciones++;
      }
      return;

    case 13:
      if(realnum == 1){
        resultado.append("N"); contador++; operaciones++;
      }
      return;

    case 14:
      if(realnum == 5){
        resultado.append("P"); contador++; operaciones++;
      }
      return;
  } 
}

void Graph::ResOperaciones(){
  cout<<"Resultado: "<<resultado<<endl;
  cout<<"Operaciones: "<<operaciones<<endl;
}
 
// Driver program to test methods of graph class
int main() {

  //input system
  string file;
  cin>>file;
  ifstream inFile;
  inFile.open(file);

  if (!inFile) {
    cerr << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
  }

  string num; //variable para el input del txt
  int counter = -1;

  string test; //varible temporal
  while (getline(inFile, test)) { //read and define num
    if(counter == 0) {
      num = test;
      counter++;
    }
    counter++;
  }

  for(int j = 0; j<=num.length()-1;j++){
    char ctemp = num[j];
    string stemp{ctemp};
    int catcher; //variable usada para verificar input correcto
    try {
      catcher = stoi(stemp);
    } 
    catch (...){
      cout<<"Input incorrecto, por favor sólo inputs númericos sin espacios 1 al 6."<<endl;
      abort();
    }
    if(catcher>6 || catcher<0){
      cout<<"Input incorrecto, por favor sólo inputs númericos sin espacios del 1 al 6."<<endl;
      abort();
    }
  }


  //contadores
  int veces = 0;
  veces = num.length()/3 + (num.length())%3; //definimos las veces que se ejecuta el método
  Graph g(15); // Total 5 vertices in graph
  g.AddEdge(0, 8);
  g.AddEdge(0, 1);
  g.AddEdge(8, 9);
  g.AddEdge(9, 10);
  g.AddEdge(9, 11);
  g.AddEdge(8, 12);
  g.AddEdge(12, 13);
  g.AddEdge(12, 14);
  g.AddEdge(1, 2);
  g.AddEdge(2, 3);
  g.AddEdge(2, 4);
  g.AddEdge(1, 5);
  g.AddEdge(5, 6);
  g.AddEdge(5, 7);
 
  auto start = high_resolution_clock::now();

  for(int i = 0; i <= veces; i++) { //repetición del método
    g.DFS(0, num);
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  g.ResOperaciones();
  cout <<"Tiempo: " << duration.count() << " microsegundos" << endl;
  
	return 0;
 
  return 0;
}