set terminal latex
set output 'gnuplot-gnuplottex-fig1.tex'
     set parametric
     set angle degree
     set urange [0:360]
     set vrange [-90:90]
     fx(u,v)=cos(u)*cos(v)
     fy(u,v)=sin(u)*cos(v)
     fz(v)=sin(v)
     splot fx(u,v),fy(u,v),fz(v)
 
