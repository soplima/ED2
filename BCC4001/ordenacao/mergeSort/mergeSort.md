# Merge Sort com Contagem de Inversões: Exemplo Passo a Passo

**Vetor de Exemplo:** `{38, 27, 43, 3, 9, 82}`  
**Objetivo:** Entender como o vetor é dividido, ordenado e como as inversões são contadas.

---

## Passo 1: Chamada Inicial
```cpp
mergeSort(v, 6); // v = {38, 27, 43, 3, 9, 82}
A função mergeSort chama merge(v, 6).

merge(v, 6); // n = 6
meio = 6 / 2 = 3

Esquerda (e): {38, 27, 43}

Direita (d): {3, 9, 82}

Chamadas recursivas:

int inversoes = merge(e, 3);    // Processa a esquerda
inversoes += merge(d, 3);       // Processa a direita

merge(e, 3); // e = {38, 27, 43}
meio = 3 / 2 = 1

Esquerda (e): {38}

Direita (d): {27, 43}

Chamadas recursivas:

merge(e, 1); // {38} → retorna 0 inversões
merge(d, 2); // {27, 43}

merge(e, 1); // e = {38}
n = 1 → retorna 0 inversões (caso base).

merge(d, 2); // d = {27, 43}
meio = 2 / 2 = 1

Esquerda (e): {27}

Direita (d): {43}

Chamadas recursivas:

merge(e, 1); // {27} → retorna 0
merge(d, 1); // {43} → retorna 0

// Comparação durante o merge:
if (e[i] <= d[j]) copia e[i], senão copia d[j] e conta inversões.
Comparações:

27 <= 43 → copia 27 → sem inversões.

Copia 43 → vetor ordenado: {27, 43}.

Inversões nesta etapa: 0.

// Comparação durante o merge:
if (e[i] <= d[j]) copia e[i], senão copia d[j] e conta inversões.
Comparações:

27 <= 43 → copia 27 → sem inversões.

Copia 43 → vetor ordenado: {27, 43}.

Inversões nesta etapa: 0.

// Comparação durante o merge:
if (38 > 27) → inversões += (1 - 0) = 1
Comparações:

38 > 27 → Inversões += 1 (elementos restantes na esquerda: 1).

38 <= 43 → copia 38.

Vetor ordenado: {27, 38, 43}.

Inversões acumuladas: 1.

merge(d, 3); // d = {3, 9, 82}
meio = 3 / 2 = 1

Esquerda (e): {3}

Direita (d): {9, 82}

Chamadas recursivas:

merge(e, 1); // {3} → retorna 0
merge(d, 2); // {9, 82}

merge(d, 2); // d = {9, 82}
meio = 2 / 2 = 1

Esquerda (e): {9}

Direita (d): {82}

Merge:

9 <= 82 → copia 9 → sem inversões.

Vetor ordenado: {9, 82}.

Inversões: 0.

// Comparação durante o merge:
if (3 <= 9) → copia 3 → sem inversões.
Comparações:

3 <= 9 → copia 3.

9 <= 82 → copia 9.

Copia 82.

Vetor ordenado: {3, 9, 82}.

Inversões: 0.

// Comparação durante o merge:
if (38 > 3) → inversões += (3 - 0) = 3
Comparações:

38 > 3 → Inversões += 3 (elementos restantes na esquerda: 3).

38 > 9 → Inversões += 3 (restantes: 3).

38 > 82 → Não.

Copia elementos restantes: 38, 43.

Vetor final ordenado: {3, 9, 27, 38, 43, 82}.

Inversões nesta etapa: 3 + 3 = 6.

Passo 12: Total de Inversões
Inversões acumuladas:

Esquerda: 1 (do merge de {38} e {27, 43}).

Direita: 0.

Merge final: 6.

Total: 1 + 0 + 6 = 7 inversões.

Resumo Final
Etapa	Inversões Contadas	Vetor Ordenado Parcial
Merge {27, 43}	0	{27, 43}
Merge {38}+{27,43}	1	{27, 38, 43}
Merge {9, 82}	0	{9, 82}
Merge {3}+{9,82}	0	{3, 9, 82}
Merge Final	6	{3, 9, 27, 38, 43, 82}