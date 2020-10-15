{$mode objfpc}
const
   InputFile  =  'VISIT.INP';
   OutputFile =  'VISIT.OUT';
var
   fi, fo : TextFile;
   n : Integer;
   T,P,l,r,lc,rc,Tc,Pc  : Int64;
procedure OpenFiles;
Begin
  AssignFile(fi, InputFile); Reset(fi);
  AssignFile(fo, OutputFile); Rewrite(fo);
end;
procedure CloseFiles;
begin
  CloseFile(fi);
  CloseFile(fo);
end;
function min(u, v : Int64) : Int64;
begin
   if u < v then min := u else min := v;
end;

procedure solve;
var i: Integer;
begin
   readln(fi, N);
   readln(fi, l, r);
   T := (r - 1) +(r - l);
   P := r - 1;
   for i := 2 to n do
   begin
     lc := l; rc := r;
     Tc := T; Pc := p;
     readln(fi, l, r);
     T := min(Tc + abs(r - lc) + (r - l) + 1,Pc + abs(r - rc) + (r - l) + 1);
     P := min(Tc + abs(l - lc) + (r - l) + 1,Pc + abs(l - rc) + (r - l) + 1);
   end;
   writeln(fo, min(T + N - l, P + N - r));
end;

BEGIN
   OpenFiles;
   Solve;
   CloseFiles;
END.
