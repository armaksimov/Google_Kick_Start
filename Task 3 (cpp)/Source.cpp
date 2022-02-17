#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

vector<int> GetHIndexScore(vector<int> citations_per_paper) {
    vector<int> h_index;
    // TODO: Calculate and return h-index score for each paper.
    int size = citations_per_paper.size();
    int H = 1;
    for (int j = 0; j < size; j++) {
        int hBiggerCount = 0;
        for (int k = 0; k <= j; k++) {
            if (citations_per_paper[k] > H) {
                hBiggerCount++;
                if (hBiggerCount > H || hBiggerCount == citations_per_paper[k]) {
                    H = hBiggerCount;
                    break;
                }
            }
        }
        h_index.push_back(H);
    }
    return h_index;
}

int main() {
    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++) {
        // Get number of papers for this test case
        int paper_count;
        cin >> paper_count;
        // Get number of citations for each paper
        vector<int> citations(paper_count);
        for (int i = 0; i < paper_count; i++) {
            cin >> citations[i];
        }
        vector<int> answer = GetHIndexScore(citations);
        cout << "Case #" << test_case << ": ";
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
