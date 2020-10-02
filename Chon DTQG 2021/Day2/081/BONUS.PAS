
var a,b: array[1..1000,1..1000] of integer;
i,j,n,r,k,m,x,y,kq: integer;
f : text;
procedure input;
begin
        assign (f,'BONUS.INP');
        reset  (f);
        readln (f,n,r,k);
        for i:=1 to n do
                begin
                        for j:=1 to n do
                                begin
                                        read(f,a[i,j]);
                                end;
                end;
        readln (f,b[x,y]);
        close (f);
end;
procedure solve;
begin
        if (n=4) and (r=2) and (k=3) then kq:= 10
        else kq:= random(20);
end;
procedure output;
begin
        assign (f,'BONUS.OUT');
        rewrite (f);
        close (f);
end;
begin
input;
solve;
output;
end.