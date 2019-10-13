def particionar(lista,inicio,fim):
    esquerda=inicio
    direita=fim
    axu=0
    pivo=lista[inicio]
    while(esquerda<direita):
        if(lista[esquerda]<=pivo):
            esquerda=esquerda+1
        if(lista[direita]>pivo):
            direita=direita-1
        if(esquerda<direita):
            aux=lista[esquerda]
            lista[esquerda]=lista[direita]
            lista[direita]=aux
    lista[inicio]=lista[direita]
    lista[direita]=pivo  
    return direita

def quick(lista,inicio,fim):
    pivo=0
    if(fim>inicio):
        pivo=particionar(lista,inicio,fim)
        quick(lista,inicio,pivo-1)
        quick(lista,pivo+1,fim)

tamanho=0
lista=[]
numero=0
i=0
print("informe o tamanho do seu vetor")
tamanho=int(input())
print("Insira o seus",tamanho,"elementos ")
while (i<tamanho):
    numero=int(input())
    lista.append(numero)
    i+=1
print("Sua lista ordenada: ")
quick(lista,0,len(lista)-1)
for i in range(0,len(lista)):
    print(lista[i])
