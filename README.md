# Checklists template in LaTex

This is a simple set of LaTex files to produce nice PDF formatted checklists.
You need to have a LaTex environment set up and `pdflatex` available.

## Creating a checklist

First create a file called `checklist.tex` on input directory. You can use any name as long the
file has the extension `.tex`.

Here's an example of a simple checklist:

```Tex
\input{input/preamble.inc}

\begin{document}

\begin{checklist}{Groceries}
  \item{Milk}{2}
  \item{Chocolate}{1 bar}
  \item{Sodas}{2}
\end{checklist}

\end{document}
```

After this, running `rake` should output a PDF file on `pdf/` directory, which
will look similar to this:

![Groceries Checklist](https://raw.githubusercontent.com/mavcunha/checklists/img/master/groceries_checklist.png)
