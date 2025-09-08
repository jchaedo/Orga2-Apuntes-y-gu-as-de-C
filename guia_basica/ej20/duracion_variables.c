int b, c;   // file scope, duración estática

void f(void)
{
    int b, d;   // block scope, duración automática
}
void g(int a)
{
    int c;  // block scope, duración automática
    {
        int a, d;   // block scope, duración automática
    }
}