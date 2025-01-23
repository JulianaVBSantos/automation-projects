import random
import string

def gerar_senha(tamanho):
    caracteres = string.ascii_letters + string.digits + "$!@_%*&()"
    senha = ''.join(random.choice(caracteres) for _ in range(tamanho))
    return senha

for i in range(77):
    senha = gerar_senha(12)
    print(f"{senha}")