DIRETORIO_TESTES=tests_binario

if [ ! -d $DIRETORIO_TESTES ]; then
    mkdir $DIRETORIO_TESTES
fi

g++ -std=c++20 \
    -Iinclude -Ivcpkg_installed/x64-linux/include \
    -Lvcpkg_installed/x64-linux/lib \
    -Lvcpkg_installed/x64-linux/lib/manual-link \
    leetcode/altura_binaria.cpp tests/test_altura.cpp \
    -lCatch2Main -lCatch2 \
    -o $DIRETORIO_TESTES/test_altura

g++ -std=c++20 \
    -Iinclude -Ivcpkg_installed/x64-linux/include \
    -Lvcpkg_installed/x64-linux/lib \
    -Lvcpkg_installed/x64-linux/lib/manual-link \
    leetcode/tamanho_binaria.cpp tests/test_tamanho.cpp \
    -lCatch2Main -lCatch2 \
    -o $DIRETORIO_TESTES/test_tamanho

for ARQUIVO in "$DIRETORIO_TESTES"/*; do
    if [ -f "$ARQUIVO" ]; then
        "$ARQUIVO"
    fi
done