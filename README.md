# Compilador C-

Um compilador completo para a linguagem C- (C minus), desenvolvido como projeto acadêmico da disciplina de Compiladores.

## 📋 Sobre o Projeto

Este projeto implementa um compilador para a linguagem C-, uma versão simplificada da linguagem C que inclui funções e arrays. O compilador é composto por todos os módulos fundamentais necessários para análise e compilação de código fonte.

## 🏗️ Arquitetura do Compilador

O compilador é estruturado nos seguintes módulos:

### 1. **Analisador Léxico (Scanner)**
- Implementado com **Flex**
- Arquivo principal: `cminus.l`
- Reconhece tokens, palavras-chave e símbolos especiais
- Processa comentários no formato `/* */`

### 2. **Analisador Sintático (Parser)**
- Implementado com **Bison**
- Arquivo principal: `cminus.y`
- Constrói a árvore sintática baseada na gramática BNF
- Detecta e reporta erros sintáticos

### 3. **Gerenciador da Tabela de Símbolos**
- Implementado em: `symtab.c`
- Utiliza tabela hash para armazenamento eficiente
- Armazena informações sobre escopo, tipo e características dos identificadores

### 4. **Analisador Semântico**
- Implementado em: `analyze.c`
- Verifica declarações de variáveis e funções
- Valida tipos e compatibilidade de operações
- Verifica chamadas de função e passagem de parâmetros

### 5. **Gerador de Código Intermediário**
- Implementado em: `cgen.c` e `code.c`
- Gera código de três endereços em formato de quádruplas
- Lineariza a árvore sintática

### 6. **Gerador de código Assembly**
- Implementado em: `assembly.c`
- Traduz o código intermediário para correspondência em Assembly

### 7. **Gerador de código Binário**
- Implementado em: `binary.c`
- Traduz o código Assembly para instruções em código binário

## 🔤 Especificações da Linguagem C-

### Palavras-chave
```
else if int return void while
```

### Símbolos Especiais
```
+ - * / < <= > >= == != = ; , () [] {} /* */
```

### Tokens
- **ID**: `letra(letra|dígito)*`
- **NUM**: `dígito(dígito)*`
- **Comentários**: `/* ... */` (não aninhados)

### Gramática BNF (Resumida)
```
programa → declaração-lista
declaração → var-declaração | fun-declaração
var-declaração → tipo-especificador ID ; | tipo-especificador ID[NUM];
fun-declaração → tipo-especificador ID(params) composto-decl
statement → expressão-decl | composto-decl | seleção-decl | iteração-decl | retorno-decl
expressão → var = expressão | simples-expressão
```

## 🚀 Como Usar

### Pré-requisitos
- GCC (GNU Compiler Collection)
- Flex (Fast Lexical Analyzer)
- Bison (GNU Parser Generator)
- Sistema Unix/Linux ou WSL

### Compilação
```bash
# Clone o repositório
git clone [url-do-repositorio]
cd c-minus-compiler

# Compile o compilador
bison -d cminus.y && flex cminus.l && gcc -c *.c && gcc -o cminus *.o -lfl
```

### Execução
```bash
# Execute um programa C-
./cminus arquivo.cminus
```

### Saída do Compilador
O compilador produz as seguintes saídas:
1. **Tokens** acompanhados de seus lexemas
2. **Árvore sintática** gerada pelo parser
3. **Tabela de símbolos** com nomes, tipos e escopos
4. **Código intermediário** em formato de três endereços
5. **Código Assembly** baseado em instruções MIPS
6. **Código binário** para arquitetura de processador construída em FPGA

## 📁 Estrutura do Projeto

```
projeto/
├── cminus.l         # Especificação léxica (Flex)
├── cminus.y         # Especificação sintática (Bison)
├── symtab.c         # Tabela de símbolos
├── analyze.c        # Analisador semântico
├── assembly.c       # Gerador de código Assembly
├── binary.c         # Gerador de código binário
├── cgen.c           # Gerador de código intermediário
├── code.c           # Funções de impressão do código
├── binaryCode.c     # Funções de emissão de instrução
├── register_bank.c  # Banco de registradores
├── globals.h        # Definições globais
├── util.c           # Funções utilitárias
├── Algorithms/      # Algoritmos para execução em FPGA
└── Tests/           # Arquivos de teste
    ├── gcd.cminus
    ├── sort.cminus
    ├── gcd_error1.cminus
    ├── gcd_error2.cminus
    ├── gcd_error3.cminus
    ├── sort_error2.cminus
    ├── sort_error2.cminus
    └── sort_error3.cminus
```

## 🧪 Testes

### Testes Válidos
- `gcd.cminus` 
- `sort.cminus`

### Testes com Erros
- `gcd_error1.cminus` e `sort_error1.cminus` - Contém erros léxicos
- `gcd_error2.cminus` e `sort_error2.cminus` - Contém erros sintáticos  
- `gcd_error3.cminus` e `sort_error3.cminus` - Contém erros semânticos

### Algoritmos para FPGA
A pasta `Algorithms/` contém 10 algoritmos desenvolvidos especificamente para execução em sistemas computacionais FPGA. 

🔗 **[Ver implementação completa do sistema FPGA →](https://github.com/gabrielaverza/MIPS-Processor-and-OS)**

## 🔍 Tipos de Erro Detectados

### Erros Léxicos
- Caracteres não reconhecidos
- Comentários mal formados

### Erros Sintáticos
- Estruturas gramaticais inválidas
- Tokens inesperados

### Erros Semânticos
- Variáveis não declaradas
- Incompatibilidade de tipos
- Chamadas de função com argumentos incorretos
- Uso de `void` em declarações de variáveis

## 🛠️ Funcionalidades Implementadas

- ✅ Análise léxica completa
- ✅ Análise sintática com recuperação de erros
- ✅ Construção de árvore sintática
- ✅ Tabela de símbolos com escopo
- ✅ Verificação semântica abrangente
- ✅ Geração de código intermediário
- ✅ Tratamento de funções e arrays
- ✅ Suporte a funções predefinidas (`input()`, `output()`)

## 📚 Referências

- **Livro**: "Compiladores: Princípios e Práticas" - Kenneth C. Louden
- **Ferramentas**: Flex & Bison para análise léxica e sintática
- **Linguagem**: Baseada em C com simplificações estruturais

## 👥 Contribuidores

Este projeto foi desenvolvido como parte da disciplina de Compiladores, demonstrando a implementação completa de um compilador funcional para uma linguagem de programação.

## ⚠️ Problemas Conhecidos

**Índices de Arrays**: Existe um problema conhecido na forma como o código trata os índices de arrays. Contribuições para correção deste problema são bem-vindas! 

🤝 **Contribua**: Se você identificou uma solução ou melhoria, fique à vontade para abrir uma *issue* ou enviar um *pull request*.

## 📄 Licença

Este projeto é de uso acadêmico e educacional.

---

*🌐 [English Version](README-EN.md)*