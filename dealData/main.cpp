#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void dealData() {
	string readFileName="line.txt";
	string writeFileName="outLine.txt";

	ifstream fin(readFileName, ios::in);
	if(!fin.is_open()) {
		cout<<readFileName<<"´ò¿ªÊ§°Ü£¡"<<endl;
		return ;
	}

	ofstream fout(writeFileName, ios::out);

	int id=1;
	while(!fin.eof()) {
		string str;
		string line;
		string station;
		vector<string> stations;

		getline(fin, str);
		stringstream ss(str);
		ss>>line;
		while(ss>>station) {
			stations.push_back(station);
		}
		fout<<"id: "<<id++<<"\n"
		    <<"name: "<<line.substr(8)<<"\n"
		    <<"fromTo: "<<stations.front()<<" "<<stations.back()<<"\n"
		    <<"totalStations: "<<stations.size()<<"\n";
		for (int i=0; i<stations.size(); ++i){
			fout<<i+1<<" "<<stations[i]<<endl;
		}
		fout<<endl;
	}
	return ;
}

int main() {
	dealData();
	return 0;
}
