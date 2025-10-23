#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int index;
    int u;
    int w;
    int d;
    double ratio;
};

void insertionSort(vector<Item>& itens) {
    for (int i = 1; i < itens.size(); i++) {
        Item chave = itens[i];
        int j = i - 1;

        while (j >= 0 &&
              (chave.ratio > itens[j].ratio ||
              (chave.ratio == itens[j].ratio && chave.index < itens[j].index))) {
            itens[j + 1] = itens[j];
            j--;
        }
        itens[j + 1] = chave;
    }
}

int main() {
    vector<Item> itens;
    int u, w, d;
    int idx = 0;

    cin >> u >> w >> d;
    while (!(u == -1 && w == -1 && d == -1)) {
        Item it;
        it.index = idx++;
        it.u = u;
        it.w = w;
        it.d = d;
        it.ratio = (double)u / w;
        itens.push_back(it);
        cin >> u >> w >> d;
    }

    int C;
    cin >> C;

    insertionSort(itens);

    vector<pair<int,int>> resposta;
    int capacidadeRestante = C;

    for (auto &it : itens) {
        if (capacidadeRestante <= 0) break;

        int maxPossivel = min(it.d, capacidadeRestante / it.w);
        if (maxPossivel > 0) {
            resposta.push_back({it.index, maxPossivel});
            capacidadeRestante -= maxPossivel * it.w;
        }
    }

    for (auto &r : resposta) {
        cout << r.first << " " << r.second << "\n";
    }

    return 0;
}
