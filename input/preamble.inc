% vim: ft=tex
\documentclass[10pt, twocolumn]{article}

\usepackage{booktabs}% def toprule, midrule and etc.
\usepackage[landscape]{geometry}
\usepackage[cm]{fullpage}
\usepackage{tikz}
\usepackage{environ}
\usepackage{fancyhdr}

\pagestyle{fancy}
\fancyhead{}
\fancyfoot{}
\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{0pt}

% draws a dashed box around to group checklists
% a task has a title, which is the group title
\NewEnviron{task}[1]{\par
\begin{tikzpicture}
\node[rectangle,minimum width=0.9\linewidth] (m) 
  {\begin{minipage}{0.85\linewidth}
    \begin{center}\uppercase{#1}\\\vspace{1em}\BODY\end{center}
   \end{minipage}};
\draw[dashed](m.south west) rectangle (m.north east);
\end{tikzpicture}\vspace{1em}
}

% checklist env sets up a table and format the items.
% in case a item has steps use the \step{asdf} 
% command.
\newenvironment{checklist}[1]{%
  \renewcommand{\item}[2]{%
    ##1\hspace{2em}\dotfill\makebox{\uppercase{##2}}\\
  }
  \newcommand{\step}[1]{%
    \hspace*{10em}-\hspace*{\labelsep}##1\\
  }
  \begin{tabular}{p{0.8\linewidth}}
     \toprule
       \multicolumn{1}{c}{\textbf{\uppercase{#1}}}\\
     \midrule
}{\bottomrule\end{tabular}\vspace{1em}}
