# Algoritmos de Ordenação - Resumo para Prova

## O que é um algoritmo de ordenação estável?

Um algoritmo é **estável** se **mantém a ordem original dos elementos iguais** após a ordenação. Isso é importante quando os dados possuem mais de um critério de ordenação.

**Exemplo:**
```python
[ ("João", 5), ("Maria", 5), ("Pedro", 3) ]
```

Ordenando por números:
- **Estável:** `[ ("Pedro", 3), ("João", 5), ("Maria", 5) ]`
- **Não estável:** `[ ("Pedro", 3), ("Maria", 5), ("João", 5) ]`

---

## Tabela Comparativa dos Algoritmos de Ordenação

| Algoritmo       | Complexidade (Média) | Complexidade (Pior Caso) | Estável? | Tipo de Técnica     | Observações |
|-----------------|--------------------------|---------------------------|------------|------------------------|-------------|
| **Selection Sort** | O(n²)                    | O(n²)                    | ❌ Não     | Comparação simples   | Pouco eficiente |
| **Bubble Sort**    | O(n²)                    | O(n²)                    | ✅ Sim     | Comparação simples   | Fácil de entender |
| **Insertion Sort** | O(n²)                    | O(n²)                    | ✅ Sim     | Comparação simples   | Bom p/ listas pequenas |
| **Merge Sort**     | O(n log n)               | O(n log n)               | ✅ Sim     | Divide e conquista     | Usa memória extra |
| **Quick Sort**     | O(n log n)               | O(n²)                    | ❌ Não     | Divide e conquista     | Muito rápido na prática |
| **Heap Sort**      | O(n log n)               | O(n log n)               | ❌ Não     | Heap (árvore binária)  | Não usa memória extra |
| **Counting Sort**  | O(n + k)                 | O(n + k)                 | ✅ Sim     | Contagem               | Para inteiros pequenos |
| **Radix Sort**     | O(nk)                    | O(nk)                    | ✅ Sim     | Por dígitos (Counting) | Usa algoritmo estável internamente |
| **Bucket Sort**    | O(n + k)                 | O(n²) (pior caso)        | ✅ Sim     | Divisão em baldes      | Bom para dados uniformes |

---

## Exemplos e Explicação de Cada Algoritmo

### 1. **Selection Sort**
**Como funciona:** A cada iteração, encontra o menor elemento e o coloca na posição correta.
```python
def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
```
**Estável:** Não

### 2. **Bubble Sort**
**Como funciona:** Troca elementos adjacentes se estiverem fora de ordem, repetidamente.
```python
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
```
**Estável:** Sim

### 3. **Insertion Sort**
**Como funciona:** Insere cada elemento na posição correta entre os anteriores.
```python
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
```
**Estável:** Sim

### 4. **Merge Sort**
**Como funciona:** Divide a lista em partes e intercala as partes ordenadas.
```python
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:]
        merge_sort(L)
        merge_sort(R)
        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] <= R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
```
**Estável:** Sim

### 5. **Quick Sort**
**Como funciona:** Escolhe um pivô e organiza os menores antes e os maiores depois.
```python
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        less = [x for x in arr[1:] if x <= pivot]
        greater = [x for x in arr[1:] if x > pivot]
        return quick_sort(less) + [pivot] + quick_sort(greater)
```
**Estável:** Não

### 6. **Heap Sort**
**Como funciona:** Constrói um heap e extrai os elementos na ordem correta.
```python
import heapq

def heap_sort(arr):
    heapq.heapify(arr)
    return [heapq.heappop(arr) for _ in range(len(arr))]
```
**Estável:** Não

### 7. **Counting Sort**
**Como funciona:** Conta quantas vezes cada valor aparece.
```python
def counting_sort(arr):
    max_val = max(arr)
    count = [0] * (max_val + 1)
    for num in arr:
        count[num] += 1
    output = []
    for i in range(len(count)):
        output.extend([i] * count[i])
    return output
```
**Estável:** Sim (se adaptado para manter ordem)

### 8. **Radix Sort**
**Como funciona:** Ordena por dígitos, da menor casa para a maior.
```python
def counting_sort_exp(arr, exp):
    output = [0] * len(arr)
    count = [0] * 10
    for i in arr:
        index = (i // exp) % 10
        count[index] += 1
    for i in range(1, 10):
        count[i] += count[i - 1]
    for i in reversed(arr):
        index = (i // exp) % 10
        output[count[index] - 1] = i
        count[index] -= 1
    return output

def radix_sort(arr):
    max_val = max(arr)
    exp = 1
    while max_val // exp > 0:
        arr = counting_sort_exp(arr, exp)
        exp *= 10
    return arr
```
**Estável:** Sim

### 9. **Bucket Sort**
**Como funciona:** Divide em baldes e ordena cada balde separadamente.
```python
def bucket_sort(arr):
    buckets = [[] for _ in range(10)]
    for num in arr:
        index = int(num * 10)
        buckets[index].append(num)
    for bucket in buckets:
        bucket.sort()
    return [num for bucket in buckets for num in bucket]
```
**Estável:** Sim

---

