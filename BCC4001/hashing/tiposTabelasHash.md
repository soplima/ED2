# Diferenças entre Tabela Hash com Endereçamento Aberto e Encadeamento Separado

Este documento resume as principais diferenças entre duas implementações de tabela hash: com endereçamento aberto e com encadeamento separado.

---

## 1. Estrutura Interna

| Característica            | Endereçamento Aberto (`thea.h`)                      | Encadeamento Separado (`thed.h`)                      |
|---------------------------|-------------------------------------------------------|--------------------------------------------------------|
| Tipo de armazenamento     | Vetor com elementos únicos                           | Vetor de listas (vetores ou listas encadeadas)         |
| Elementos por posição     | Apenas um elemento por posição                       | Múltiplos elementos por posição                        |

---

## 2. Tratamento de Colisões

| Característica        | Endereçamento Aberto                  | Encadeamento Separado                     |
|-----------------------|----------------------------------------|-------------------------------------------|
| Método utilizado      | Sondagem linear                       | Lista de pares na mesma posição           |
| Resolução de conflito | Procura próxima posição livre         | Adiciona na lista associada               |

---

## 3. Inserção

- **Endereçamento Aberto**: Verifica colisões e tenta outras posições via sondagem.
- **Encadeamento Separado**: Insere diretamente na lista da posição calculada.

---

## 4. Remoção

- **Endereçamento Aberto**: Marca o item como "APAGADO".
- **Encadeamento Separado**: Remove diretamente da lista.

---

## 5. Redimensionamento

- Ambas implementações redimensionam quando um limiar de carga é ultrapassado.
- **Endereçamento Aberto** tende a dobrar o vetor e reinserir tudo.
- **Encadeamento Separado** reinicializa todas as listas com nova função hash.

---

## 6. Desempenho

| Situação                 | Endereçamento Aberto        | Encadeamento Separado           |
|--------------------------|-----------------------------|----------------------------------|
| Uso de memória           | Mais eficiente               | Usa memória extra para listas   |
| Boa com carga baixa?     | Sim                          | Sim                              |
| Boa com muitas colisões? | Não                          | Sim                              |
| Remoção eficiente?       | Não (marca como apagado)     | Sim                              |

---

## 7. Exemplo Ilustrativo

### Endereçamento Aberto
```text
tabela[0] = (15, "A") // OCUPADO
tabela[1] = (23, "B") // OCUPADO
tabela[2] = LIVRE

### Encadeamento Separado
tabela[0] = [(15, "A"), (30, "B")]
tabela[1] = []
tabela[2] = [(42, "C")]
---
###Conclusão
Endereçamento Aberto: Mais simples e eficiente com poucos dados e baixa colisão.

Encadeamento Separado: Mais robusto, lida melhor com colisões e remoções frequentes.