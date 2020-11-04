uses crt;
var a,b:string; t,i:integer;
     x,y:qword;
function add(a,b:string):string;
var sum,carry,i,x,y:integer;
     c:string;
begin
     carry:=0;c:='';
     while length(a)<length(b) do a:='0'+a;
     while length(b)<length(a) do b:='0'+b;
     for i:=length(a) downto 1 do
     begin
           x:= ord(a[i])-ord('0');
           y:= ord(b[i])-ord('0');
           sum:=x + y + carry;
           carry:=sum div 10;
           c:=chr(sum mod 10 +48)+c;
     end;
     if carry>0 then c:='1'+c;
     add:=c;
end;
begin
   read(t);
   for i:=1 to t do
   begin
      read(x,y);
      str(x,a);
      str(y,b);
      writeln(add(a,b)) ;
   end;
end.

