#include <iostream> 
#include <algorithm>
#include <list> 
#include <vector> 
#include <deque>
#include <queue>


#define FOR(i, s, e) for(int i = s; i < e; i++)
using namespace std;

int main(){
    vector <int> gl;
    gl.push_back(10);
    cout << gl.size() << "\n";
    FOR(i, 0, 10){
        gl.push_back(i);
    }
    FOR(j, 0, 10){
        gl.push_back(j);
    }

    for(auto x: gl){
        cout << x << endl;
    }
    deque <int> gquiz;
    gquiz.push_back(10);
    gquiz.push_front(20);


    cout << gquiz.front() << endl;
    
    priority_queue <int> pq; 
    FOR(i, 0, 10){
        pq.push(rand()%1000);
    }
    while(!pq.empty()){
        cout<<pq.top() << endl;
        pq.pop();
    }
}
