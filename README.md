# 📚 C++ Rank 05 — 42 School

Este repositório contém a resolução completa dos módulos **CPP05 ao CPP09** do cursus da 42.

O objetivo principal não é apenas entregar os exercícios, mas **construir domínio real em C++ (C++98)**, com foco em:
* Programação Orientada a Objetos (OOP)
* Design de classes
* Templates
* STL (containers, iterators e algoritmos)
* Boas práticas exigidas pela 42

---

# 🎯 Objetivo do Repositório

Este repositório foi estruturado para:
* Organizar os exercícios por módulo e por exercício
* Documentar o processo de aprendizado
* Facilitar revisões futuras (inclusive para exames)
* Garantir aderência total às regras da 42
* Simular um ambiente profissional com versionamento disciplinado

---

# 📁 Estrutura do Projeto

```
cpp_rank05/
├── README.md
├── .gitignore
├── docs/
│   ├── subjects/
│   │   ├── cpp05.pdf
│   │   ├── cpp06.pdf
│   │   ├── cpp07.pdf
│   │   ├── cpp08.pdf
│   │   └── cpp09.pdf
│   ├── notes/
│   │   ├── cpp05/
│   │   ├── cpp06/
│   │   ├── cpp07/
│   │   ├── cpp08/
│   │   └── cpp09/
│   └── diagrams/
├── cpp05/
│   ├── ex00/
│   ├── ex01/
│   ├── ex02/
│   └── ex03/
├── cpp06/
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
├── cpp07/
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
├── cpp08/
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
└── cpp09/
    ├── ex00/
    ├── ex01/
    └── ex02/
```

---

# ⚙️ Regras Gerais (Baseadas no Subject Oficial)

## Compilação

* Compilar com:
```bash
c++ -Wall -Wextra -Werror
```

* Código deve ser compatível com:
```bash
-std=c++98
```

---

## Convenções de Código

* Diretórios nomeados como:
```
ex00, ex01, ex02, ...
```

* Classes em:
```
UpperCamelCase
```

* Arquivos devem seguir o nome da classe:
```
ClassName.hpp
ClassName.cpp
```

* Cada saída deve terminar com `\n`

---

## Restrições

* Proibido usar bibliotecas externas (Boost, C++11+ etc.)
* Proibido:
  * `printf`
  * `malloc/free`
* `using namespace` (salvo exceção explícita)
* `friend` (salvo exceção explícita)

---

## Design de Código

* Todas as classes (CPP02 → CPP09) devem seguir:
```
Orthodox Canonical Form
```

Ou seja, implementar:
* Default constructor
* Copy constructor
* Copy assignment operator
* Destructor

---

## Headers

* Devem ser **independentes**
* Devem conter **include guards**
* Devem incluir todas as dependências necessárias

---

## Implementação

* Implementação em `.hpp` → proibido
    * EXCEÇÃO: Templates (CPP07)

---

# 📦 Regras por Módulo

## CPP05 — Exceptions & OOP

* Foco em:
  * Exceptions
  * Encadeamento de classes
  * Responsabilidade de objetos
* Exercícios são progressivos (dependem uns dos outros)

---

## CPP06 — Casts

* Uso correto de:
  * static_cast
  * dynamic_cast
  * reinterpret_cast
* Cada exercício valida um tipo específico de conversão

---

## CPP07 — Templates

* Introdução a:
  * Function templates
  * Class templates

⚠️ Regra importante:

* Templates devem ser implementados em headers (`.hpp`) ou `.tpp`

---

## CPP08 — STL (Introdução)

* Uso de:
  * Containers (vector, list, map…)
  * Algoritmos (`<algorithm>`)

⚠️ Esperado:

* Uso ativo da STL
* Não usar STL pode impactar a nota negativamente

---

## CPP09 — STL (Avançado)

* Uso obrigatório de containers

⚠️ Regras importantes:

* Cada exercício deve usar um container diferente
* Containers usados não podem ser reutilizados nos próximos exercícios
* ex02 exige uso de **dois containers diferentes**

---

# 🌿 Git Workflow

## Branches

Uma branch por exercício:
```
feature/cpp05-ex00
feature/cpp05-ex01
feature/cpp06-ex00
feature/cpp07-ex02
...
```

Branches auxiliares:
```
fix/...
refactor/...
docs/...
chore/...
```

---

## Commits (Conventional Commits)

Formato:
```
type(scope): message
```

### Tipos:

* feat
* fix
* refactor
* test
* docs
* chore

### Exemplos:

```
feat(cpp05/ex00): implement Bureaucrat class
fix(cpp05/ex01): handle invalid grade exception
refactor(cpp06/ex00): simplify scalar conversion logic
feat(cpp07/ex02): implement Array template with bounds check
feat(cpp08/ex01): add shortestSpan and longestSpan
feat(cpp09/ex02): implement merge-insert sort
```

---

# 🧪 Testes

* Cada exercício deve conter um `main.cpp`
* `main.cpp` funciona como:
  * teste manual
  * validação de comportamento
  * preparação para defesa

---

# 📖 Documentação

A pasta `docs/` contém:
* Subjects oficiais
* Notas de estudo
* Diagramas
* Anotações de defesa

---

# 🧠 Filosofia de Aprendizado (42)

Este repositório segue os princípios da 42:
* Construir raciocínio próprio
* Evitar atalhos
* Priorizar entendimento sobre resultado
* Aprender com erro e repetição
* Ser capaz de explicar o código em uma avaliação

---

# ⚠️ Observações Importantes

* Código deve ser **legível e compreensível**
* Avaliadores podem pedir:
  * modificações rápidas
  * explicações detalhadas
* Código que não é compreendido → não é avaliado

---

# 🚀 Próximos Passos

* Implementação progressiva dos módulos
* Revisões e refatorações após cada exercício
* Preparação contínua para avaliação entre pares

---

# ✨ Autor

Projeto desenvolvido como parte do cursus da **42 School**.

---
