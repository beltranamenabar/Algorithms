#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<vector<int> > &A, int B){
	vector<bool> Visitados(false, A.size());
	vector<int> Distancia;
	queue<int> Cola;
	Distancia[B] = 0;
	Cola.push(B);
	while (!Cola.empty()) {
		int u = Cola.front();
		Cola.pop();
		if (!Visitados[u]) {
			Visitados[u] = true;
			for (int i = 0; i < A[u].size(); i++) {
				Cola.push(A[u][i]);
				Distancia[A[u][i]] = Distancia[u] + 1;
			}
		}	
	}
	return Distancia;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, j, k;
	cin >> n >> m;
	vector<vector<int> > G(n);
	
	for (int i = 0; i < m; i++) {
		cin >> j;
		cin >> k;
		G[j - 1].push_back(k - 1);
		G[k - 1].push_back(j - 1);
	}
	vector<int> distMin;
	int indice;
	cin >> indice;
	distMin = BFS(G, indice - 1);
	cout << "A partir del vertice " << indice << " las distancias son:\n";
	for (int i = 0; i < distMin.size(); i++) {
		cout << i + 1 << " - " << distMin[i] << '\n';
	}
	return 0;
}
