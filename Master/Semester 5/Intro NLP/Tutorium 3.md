[[NLP-Tutorial3.pdf]]
## TF-IDF

- probabilistic information about words
- metric/statistic
- TF: Term Frequency
- IDF: Inverse Document Frequency

$$TF=\frac{\#\text{occurences of word}}{\#\text{words in document}}$$
$$IDF=\log\left( \frac{\#\text{documents}}{\#\text{documents containing word}+1} \right)$$

## Word Embeddings

- no absolute information, only relative ones
	- one-way transformation (word -> embedding)
- sparse embedding: high dim, mostly 0
- dense embedding: lower dim, mostly non-0
	- besser

Word2Vec: next token prediction

Similar words have high cosine similarity (vectors point in same direction)


BERT: sentence embedding
