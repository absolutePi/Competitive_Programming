#include <bits/stdc++.h>
using namespace std;

int N, M;
// {s, t, c}
vector<array<int, 3>> cows;
// {a, b, p, m}
vector<array<int, 4>> air_conditioners;
// uses[i] == true: the i-th air conditioner is used
vector<bool> uses;
// the minimum amount of money needed to keep all cows comfortable
int min_cost = numeric_limits<int>().max();

/**
 * Based on 'uses', determine if the current subset of air conditioners suffices
 * the constraints, and if so, update the minimum cost
 */
void update() {
	bool is_feasible = true;

	// iterate through all positions to check if the current subset is feasible
	for (int i = 1; i <= 100; i++) {
		// iterate through air conditioners to find the current cooling units
		int cooling = 0;
		for (int j = 0; j < M; j++) {
			if (!uses[j]) { continue; }
			auto &[a, b, p, m] = air_conditioners[j];
			if (a <= i && i <= b) { cooling += p; }
		}

		// iterate through cows to find the current cow
		int cow_requirement = 0;
		for (int j = 0; j < N; j++) {
			auto &[s, t, c] = cows[j];
			if (s <= i && i <= t) {
				cow_requirement = c;
				break;
			}
		}

		// For each position, the requirement of the cow must be met
		if (cooling < cow_requirement) {
			is_feasible = false;
			break;
		}
	}

	if (is_feasible) {
		int cost = 0;
		for (int i = 0; i < M; i++) {
			if (uses[i]) { cost += air_conditioners[i][3]; }
		}
		min_cost = min(min_cost, cost);
	}
}

/**
 * Expand the subset, represented by 'uses', by choosing to (not) use the i-th
 * air conditioner
 */
void search(int i) {
	if (i == M) {
		update();
	} else {
		uses[i] = true;
		search(i + 1);
        uses[i] = false;
		search(i + 1);
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int s, t, c;
		cin >> s >> t >> c;
		cows.push_back({s, t, c});
	}

	for (int i = 0; i < M; i++) {
		int a, b, p, m;
		cin >> a >> b >> p >> m;
		air_conditioners.push_back({a, b, p, m});
	}

	uses.assign(M, false);
	search(0);

	cout << min_cost << endl;
}
