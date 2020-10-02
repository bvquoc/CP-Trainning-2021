
var a,b: array[1..1000000] of int64;
    n,i,j,k,m: longint;
    dem,tam,tam1,tt,tr: integer;
    f: text;
procedure input;
var f: text;
begin
        assign (f,'IQ.INP');
        reset  (f);
        readln (f,n);
        for i:=1 to n do read (f,a[i]); writeln;
        for k:=1 to n do read (f,b[k]);
        close (f);
end;
procedure solve;
begin
        for i:=1 to n-1 do
        for j:=i+1 to n do
                if a[j] > a[i] then
                        begin
                                tam:= a[i];
                                a[i]:=a[j];
                                a[j]:= tam;
                        end;
        for k:=1 to n-1 do
        for m:=k+1 to n do
                if b[m] > b[k] then
                        begin
                                tam1:=b[k];
                                b[k]:=b[m];
                                b[m]:=tam1;
                        end;
        readln;
        tt:=1;
        dem:=0;
        for k:=1 to n do
                begin
                        tr:=0;
                        for i:=tt to n+1 do
                                begin
                                        if i= n+1 then break;
                                        if b[k] > a[i] then
                                                begin
                                                        dem:= dem +1;
                                                        tt:=i+1;
                                                        tr:=1;
                                                end;
                                        if tr=1 then break;
                                end;
                end;
end;
procedure output;
var f: text;
begin
        assign (f,'IQ.OUT');
        rewrite (f);
        write (f,dem);
        close (f);
end;
begin
input;
solve;
output;
write (dem);

end.
