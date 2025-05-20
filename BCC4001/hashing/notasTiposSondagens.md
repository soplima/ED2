
//! Condicao de uso para a sondagem quadratica -> a < 1/2  e M >= 3 e M precisa ser primo. 

// O hash calcula a posição inicial, mas não garante que essa posição estará livre.
// Quando ela está ocupada, usamos sondagem para procurar outra posição alternativa sem perder o controle da ordem.

# Técnicas de Sondagem em Tabelas Hash

Quando ocorre uma colisão (duas chaves sendo mapeadas para a mesma posição), usamos **técnicas de sondagem** para encontrar a próxima posição disponível dentro da tabela hash.

---

## 📊 Comparativo Geral

| Técnica            | Fórmula                        | Comportamento      |
|--------------------|--------------------------------|--------------------|
| **Linear**         | `(h + k) % M`                  | Busca sequencial   |
| **Quadrática**     | `(h + k²) % M`                 | Crescimento rápido |
| **Dupla (double)** | `(h1 + k × h2) % M`            | Salto controlado   |

---

## 🔁 1. Sondagem Linear

### 📌 Fórmula

##pos = (h + k) % M


- `h`: valor inicial calculado pela função hash (`h = chave % M`)
- `k`: número da tentativa (0, 1, 2, ...)
- `M`: tamanho da tabela hash

### 🔎 Funcionamento

A cada colisão, tenta a **próxima posição sequencial**:

Exemplo:  
Se `h = 3` e `M = 7`, as posições tentadas serão:  
`3, 4, 5, 6, 0, 1, 2, ...`

### ⚠️ Vantagens e Desvantagens

- ✅ Simples de implementar
- ❌ Pode causar **agrupamento primário** (vários elementos consecutivos agrupados, o que degrada a performance)

---

## 🌀 2. Sondagem Quadrática

### 📌 Fórmula

##pos = (h + k²) % M


- `h`: valor inicial da função hash
- `k`: número da tentativa (0, 1, 2, ...)
- `M`: tamanho da tabela

### 🔎 Funcionamento

Tenta posições com **crescimento quadrático** em relação ao número de tentativas:

Exemplo:  
Se `h = 3` e `M = 7`, as posições serão:  
`3, 4 (3+1²), 7→0 (3+2²), 3+9→12→5, ...`

### ⚠️ Vantagens e Desvantagens

- ✅ Evita agrupamento primário
- ❌ Pode causar **agrupamento secundário** (elementos com mesmo hash exploram as mesmas posições)
- ❌ Nem sempre garante acesso a todas as posições se `M` não for primo

---

## 🧮 3. Sondagem Dupla (Double Hashing)

### 📌 Fórmula

##pos = (h1(chave) + k × (h2(chave) + 1)) % M


- `h1`: primeira função hash → `chave % M`
- `h2`: segunda função hash → comum usar `1 + (chave % (M - 1))`
- `k`: número da tentativa
- `M`: tamanho da tabela (recomendado ser **número primo**)

### 🔎 Funcionamento

Em vez de testar posições fixas (como na linear ou quadrática), a segunda função `h2` define o tamanho do salto. Isso permite uma **dispersão mais eficiente**:

Exemplo:
```cpp
h1(k) = k % M
h2(k) = 1 + (k % (M - 2))

