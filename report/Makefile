AUTHOR = charlesGoedefroit
MAIN_TEX = report

TEX = pdflatex
TEX_ARG = -interaction=nonstopmode -file-line-error -shell-escape

all: $(MAIN_TEX)-$(AUTHOR).pdf

clean:
	rm -f *.dvi *.eps *.log *.aux *.toc *.bbl *.blg _minted*/* *.synctex.gz
	rm -f $(MAIN_TEX)-$(AUTHOR).pdf $(MAIN_TEX).pdf

$(MAIN_TEX)-$(AUTHOR).pdf: $(MAIN_TEX).pdf
	ln -f $(MAIN_TEX).pdf $(MAIN_TEX)-$(AUTHOR).pdf

.SUFFIXES: .pdf .tex

$(MAIN_TEX).pdf:
	$(TEX) $(TEX_ARG) $(MAIN_TEX).tex