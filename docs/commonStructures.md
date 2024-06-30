## 2dVector
A basic 2d vector struct stores x and y.
```c
typedef struct s_2dVector {
    int x;
    int y;
}   t_2dVector;
```

## getAndInitStruct
Function that allocate struct with zero values and protect garbage values after allocatin memory.
```c
void	*getAndInitStruct(int number, size_t size, void (* initStruct)(void *));
```
* **number**: Number of the struct we need.
* **size**: sizeof struct.
* **initStruct**: Init function for the struct (puts 0 on every property).

Example is:
```c
void	init2dVector(void *p) {
	t_2dVector	*v = (t_2dVector *)p;
	(*v).x = 0;
	(*v).y = 0;
}

int main() {
    // Allocate and initialize 5 t_2dVector
    t_2dVector *vector = (t_2dVector *)getAndInitStruct(5, sizeof(t_2dVector), &init2dVector);
}
```