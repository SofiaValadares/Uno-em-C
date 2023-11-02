@echo off

rem Verifica se o diretório "bin" existe e, se não, o cria.
if not exist bin mkdir bin

rem Compila o código C e gera o executável "saida.exe".
gcc main.c .\funcs\*.c -I include -o bin\saida.exe

rem Verifica se a compilação foi bem-sucedida e, em caso de erro, exibe uma mensagem.
if errorlevel 1 (
  echo Compilação falhou. Verifique os erros acima.
  pause
) else (
  rem Executa o programa "saida.exe" a partir do diretório "bin".
  .\bin\saida.exe

  rem Pausa para que você possa ver a saída antes de fechar a janela.
  pause
)