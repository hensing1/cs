## Recurrent Neural Nets

- haben internen Zustand
- $h_{t}=\tanh(W_{hh}h_{t-1}+W_{xh}x_{t})$, mit Input $x$ utd Zustand $h$
- Ableitung von tanh bei 0 ist 1, sonst kleiner
- vanishing gradients problem
- interner Zustand ist kurzweilig (wird von neuen Inputs stärker beeinflusst)

## LSTM

Long-Short Term Memory network

- löst nicht vanishing gradients, aber ist besser als RNN