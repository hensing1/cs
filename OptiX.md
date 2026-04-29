*Nvidia Ray Tracing Framework*

API-Schnittstellen in grün:
![[OptiX-API.png|404]]

OpenGL-Interop möglich

Logging interface:
`optixDeviceContextSetLocCallback( )`

## Ray Generation

- `extern "C"` um name mangling zu vermeiden
- `__global__` als Indikator für CUDA, damit Funktion auf Grafikkarte läuft
- Prefix `__raygen__` für OptiX

```c++
extern "C" __global__ void __raygen__rg() {

}
```



weitere:
- `__miss__`
- `__closesthit__`
- `__intersection__`
- `__anyhit__`


