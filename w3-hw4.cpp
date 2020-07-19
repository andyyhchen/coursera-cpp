#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define NUM 5

class HQ{
private:
	string color;
	int counts[NUM];
	int* orders, *lives;
	int time, curType, totalLives;
	bool stopped;

	void Print(int t){
		string names[]={"dragon", "ninja", "iceman", "lion", "wolf" };
		if(t >= 0){
			printf("%03d ", time-1);
			cout<<color<<" "<<names[orders[t]]<<" "<< time <<" born with strength " << lives[orders[t]]<<","<<counts[t]<<" "<< names[orders[t]]<<" in "<<color<<" headquarter\n";
			return;
		}
		printf("%03d ", time-1);
		cout <<color<<" headquarter stops making warriors\n";
		return;
	}
	


public: 
	HQ(string col, int tl, int *od, int *li):color(col), totalLives(tl), orders(od), lives(li){
		for(int i = 0; i < NUM; i++)
			counts[i] = 0;
		time = 0; curType = 0; stopped = false;
		
	}

	bool isStopped(){
		return stopped;
	}
	
	void produce(){
		if (isStopped()){
			return;
		}
		time++;
		for(int i = 0; i < NUM; i++){
			int tmp = (curType + i) % NUM;
			if(totalLives >= lives[orders[tmp]]){
				counts[tmp]++;
				totalLives -= lives[orders[tmp]];
				curType=(tmp+1)%NUM;
				Print(tmp);
				return;
			}
		}

			stopped = true;
			Print(-1);
			return; 
	}

};


int main()
{
	int n, M;
	int lives_[NUM];
	cin >> n;
	for(int k = 0; k < n; k++){
		cin >> M;
		for(int i = 0; i < NUM; i++) cin >> lives_[i];
		//dragon", "ninja", "iceman", "lion", "wolf"
		int ro[NUM] = {2, 3, 4, 1, 0};
		int bo[NUM] = {3, 0, 1, 2, 4};
		HQ red("red", M, ro, lives_);
		HQ blue("blue", M, bo, lives_);
		cout << "Case:"<<k+1<<"\n";
		while(!red.isStopped() || !blue.isStopped()){
			red.produce();
			blue.produce();
		}

	}

	return 0;
}