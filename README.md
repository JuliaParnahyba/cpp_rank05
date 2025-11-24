# 🚀 42 C++ Modules — Rank 05

Este é o repositório onde documento meu progresso na trilha de **C++ da 42**, agora avançando para os módulos **05 a 09**, que compõem o novo *rank* da formação.
A partir daqui, o foco passa a ser **exceções, casts, templates, containers STL e pequenos projetos práticos**.

<br>

## 🧠 Sobre o projeto

Este conjunto de módulos aprofunda conceitos essenciais da linguagem **C++98**, evoluindo da base sólida do Rank04 para temas mais avançados.
Entre os principais assuntos abordados estão:

* Tratamento de **exceções** e regras de negócio (Bureaucrats & Forms)
* **Casts** (`static_cast`, `reinterpret_cast`, `dynamic_cast`) e RTTI
* **Templates** de funções e classes
* Conceitos fundamentais da **STL** (containers, iteradores e algoritmos)
* Implementação de estruturas customizadas e frameworks mini-STL
* Desenvolvimento de pequenos projetos práticos com **map, stack, deque, vector, parsing e performance**

<br>

## 📦 Estrutura do Repositório

```bash
cpp_rank05/
├── cpp05/
│   ├── ex00/        # Bureaucrat – Exceptions Básicas
│   ├── ex01/        # Forms – Assinatura e Validações
│   └── ex02/        # AForm – Polimorfismo e Execução
│
├── docs/
│   ├── subjects/    # Subjects oficiais do Módulo 05 ao 09
│   │   ├── pt_br.subject_Módulo05.pdf
│   │   ├── pt_br.subject_Módulo06.pdf
│   │   ├── pt_br.subject_Módulo07.pdf
│   │   ├── pt_br.subject_Módulo08.pdf
│   │   └── pt_br.subject_Módulo09.pdf
│   ├── notes/       # Notas e resumos para estudo e defesa
│   └── diagrams/    # Diagramas UML e fluxos
│
├── .github/
│   ├── ISSUE_TEMPLATE/
│   ├── PULL_REQUEST_TEMPLATE.md
│   └── workflows/
│
├── .gitignore
└── README.md
```

<br>

## 📚 Módulos e Conceitos

| Módulo    | Conceitos Abordados                                                                       | Status         |
| --------- | ----------------------------------------------------------------------------------------- | -------------- |
| Module 05 | Exceptions, regras de negócio, validação, formulários e polimorfismo                      | ⏳ Em andamento |
| Module 06 | Casts, conversão de tipos, ponteiros vs inteiros, RTTI                                    | ⏳ A iniciar    |
| Module 07 | Templates, funções genéricas, classes template, arrays customizados                       | ⏳ A iniciar    |
| Module 08 | Containers, iteradores, algoritmos, `std::list`, `std::vector`, `std::stack`, `std::find` | ⏳ A iniciar    |
| Module 09 | Projetos STL: BitcoinExchange, RPN, PmergeMe (sorting & performance)                      | ⏳ A iniciar    |

> ⚠️ *O uso da STL passa a ser permitido oficialmente no Módulo 08.
> Para M05–M07, apenas containers/algoritmos implícitos ou padrão do subject.*

<br>

## 🧪 Compilação

Todos os exercícios devem ser compilados seguindo a norma da 42:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

Cada exercício possui seu próprio `Makefile` com as regras padrões:

* `all`
* `clean`
* `fclean`
* `re`

<br>

## 🧯 Restrições

* ❌ Não usar: `printf`, `malloc`, `free`, `using namespace`, `friend`
* ❌ Nos módulos 05–07: **não usar containers ou algoritmos da STL**, exceto se explicitamente permitido
* ✅ `std::exception`, mensagens customizadas, classes aninhadas e exceções próprias são permitidas
* ✅ A partir do M08: uso completo de containers e algoritmos STL

<br>

## 🧩 Padrões e Normas

Todos os exercícios seguem as diretrizes oficiais da 42:

* Orthodox Canonical Form (OCF) sempre que solicitado
* Clareza, modularidade e código autodocumentado
* Tratamento de exceções elegante e consistente
* Separação em headers e fontes (`.hpp` e `.cpp`)
* Encapsulamento forte e foco em boas práticas OOP
* Estilo de commit usando **Conventional Commits**
* Organização via **GitHub Projects**, templates e automações

<br>

## 🧑‍💻 Autora

### Julia Parnahyba

Estudante de Engenharia de Software | [42 Rio](https://42.rio)
LinkedIn: [Julia Parnahyba](https://www.linkedin.com/in/juliaparnahyba/)
GitHub: [JuliaParnahyba](https://github.com/JuliaParnahyba)

<br>

*“By Odin, by Thor! Use your brain!” – Subject dos módulos*

