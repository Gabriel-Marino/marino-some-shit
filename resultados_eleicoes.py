#   Estudar o código aqui: https://colab.research.google.com/drive/1n4XAEyNBrBzWQBQC8KJcnE-WOI42LeS9
#   Inspirado por:  https://twitter.com/BrennoSullivan/status/1576655828089974785

from json import loads
from os import system, getpid
from pandas import DataFrame
from requests import get
from time import sleep, ctime

while True:
    json_data = loads(get("https://resultados.tse.jus.br/oficial/ele2022/544/dados-simplificados/br/br-c0001-e000544-r.json").content)  #   Solicita os dados dos candidatos a presidência da API do TSE-BR.

    sep_data = [
        [[], 'nm'],     #   candidatos.
        [[], 'vap'],    #   número de votos.
        [[], 'pvap']    #   porcentagem.
        ]

    list(map(lambda data: list(map(lambda info: data[0].append(info[data[1]]) if info['seq'] in '1 2'.split(' ') else 0, json_data['cand'])), sep_data))

    system('clear')     #   limpa o console antes de imprimir dados novos.
    print(ctime())      #   Imprime a data e hora atual.
    print(DataFrame(list(zip(sep_data[0][0], sep_data[1][0], sep_data[2][0])), columns=['Candidato', '# votos', 'Porcentagem']))        #   Cria a tabela para mostrar os dados mais organizadamente.

    system('kill -9 {}'.format(getpid())) if float(json_data[''].replace(',', '.')) >= 99 else sleep(300)    #   Para o laço caso tenha apurado 99% das urnas, caso contrário espera por 5 minutos antes de imprimir os dados novos.