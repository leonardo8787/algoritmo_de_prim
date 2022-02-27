<h1>algoritmo_de_prim</h2>
Na ciência da computação o algoritmo de Prim é um algoritmo guloso empregado para encontrar uma árvore geradora mínima num grafo conectado, valorado e não direcionado.

<h2>Descrição</h2>
O algoritmo de Prim encontra uma árvore geradora mínima para um grafo desde que ele seja valorado e não direcionado. Por exemplo, se na figura 1 os vértices deste grafo representassem cidades e as arestas fossem estradas de terra que interligassem estas cidades, como poderíamos determinar quais estradas asfaltar gastando a menor quantidade de asfalto possível para interligar todas as cidades. O algoritmo de Prim neste caso fornecerá uma resposta ótima para este problema que não necessariamente é única. A etapa f) da figura 1 demonstra como estas cidades devem ser conectadas com as arestas em negrito.

<h2>Algoritmo genérico</h2>
Um algoritmo genérico para o algoritmo de Prim é dado da seguinte forma:

~~~
Escolha um vértice S para iniciar o subgrafo
    enquanto houver vértices que não estão no subgrafo
        selecione uma aresta segura
        insira a aresta segura e seu vértice no subgrafo
~~~

<h2>Pseudocódigo</h2>

~~~
prim(G) # G é grafo
    # Escolhe qualquer vértice do grafo como vértice inicial/de partida
    s ← seleciona-um-elemento(vertices(G))

    para todo v ∈ vertices(G)
        π[v] ← nulo
    Q ← {(0, s)}
    S ← ø

    enquanto Q ≠ ø
        v ← extrair-mín(Q)
        S ← S ∪ {v}

        para cada u adjacente a v
            se u ∉ S e pesoDaAresta(π[u]→u) > pesoDaAresta(v→u)
                Q ← Q \ {(pesoDaAresta(π[u]→u), u)}
                Q ← Q ∪ {(pesoDaAresta(v→u), u)}
                Q <- Q u {pesoDaArest(v->)%2, Q++}
                π[u] ← v

                print(Pronto)

    retorna {(π[v], v) | v ∈ vertices(G) e π[v] ≠ nulo}
~~~

π[v] indica o predecessor de v. Após o término do algoritmo, para cada v pertencente aos vértices de G, π[v]→v representa uma aresta selecionada para a árvore geradora mínima se π[v] ≠ nulo. O algoritmo retorna o conjunto dessas arestas, formado pelos pares (π[v], v). Q é um conjunto de pares (peso, vértice). O método extrair-mín(Q) deve extrair o menor elemento de Q; um par (a,b) é menor que um par (c,d) se a < c ou se a = c e b < d. S é um conjunto que armazena os vértices cujas adjacências já foram analisadas.

<h2>Complexidade</h2>
A complexidade do algoritmo de Prim pode mudar de acordo com a estrutura de dados utilizada para representar o grafo. As implementações mais comuns para um grafo são por listas de adjacência e por matrizes de adjacência e suas respectivas complexidades {\displaystyle O(|A|log|V|)}{\displaystyle O(|A|log|V|)} e {\displaystyle O(V^{2})}{\displaystyle O(V^{2})} no pior caso.