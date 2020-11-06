uses crt;
const nmax=1000000;
var     k,t:int64;
        a:array[0..nmax] of int64;
        i,j:longint;
begin
      readln(k);
      for j:=0 to nmax  do
      begin
          a[j]:=sqr(j);
          t:=k+a[j];
          if t<0 then continue;
          if trunc(sqrt(t))=sqrt(t) then begin
                               write(trunc(sqrt(t)));
                               break;
                             end;
      end;
      if j=nmax then write('none');
end.















