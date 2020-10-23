 var f,g:text; s,xau,xautam: ansistring; i,n,so,j,vt:longint;

 begin
  assign(f,'SIMI.INP'); reset(f);
  assign(g,'SIMI.OUT'); rewrite(g);
  readln(f,s);
  n:=length(s);
  so:=n;
  for i:=2 to n do
   begin
    xau:=copy(s,i,n-i+1);
    for j:=1 to length(xau) do
     begin
      xautam:=copy(xau,1,j);
      vt:=pos(xautam,s);
      if vt=1 then begin so:=so+1;  end else break;
     end;
   end;
  write(g,so);
  close(f); close(g);
 end.
