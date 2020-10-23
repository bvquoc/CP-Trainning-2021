 type vector=array[0..10000] of longint;
 var m,n,d:longint; A,x:vector; f,g:Text;
     B:array[0..1] of string;

 function check(x:vector):boolean;
 var j2,so,m:longint;
 begin
  so:=A[1];
  for j2:=1 to n-1 do
   if x[j2]=0 then so:=so+A[j2+1]
    else so:=so-A[j2];
  if so mod m = 0 then exit(true) else exit(false);
 end;

 procedure lap(i:longint);
 var j,j1:longint;
 begin
  if d=1 then
  for j:=0 to 1 do
   begin
    x[i]:=j;
    if i=n-1 then
     begin
      if check(x) then
       begin
        d:=0;
        writeln(g,1);
        for j1:=1 to n-1 do write(g,B[x[j1]]);
       end;
      end
     else begin if d=1 then lap(i+1) else exit; end;
   end;
 end;


 begin
  assign(f,'KMULT.INP'); reset(f);
  assign(g,'KMULT.OUT'); rewrite(g);
  readln(f,n,m);
  for d:=1 to n do read(f,A[D]);
  B[0]:='-';B[1]:='+';
  d:=1;
  lap(1);
  if d=1 then write(g,0);
  close(f); close(g);
 end.
