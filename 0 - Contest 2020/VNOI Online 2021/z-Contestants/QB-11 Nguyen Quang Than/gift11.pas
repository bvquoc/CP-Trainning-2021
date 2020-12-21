program Permutation;
const
	fi = 'gift11.INP';
	fo = 'gift11.OUT';
	max = 12;
var
	n,res, i, k, a,q, b,j,u,l: longint;
	x,s: array[1..max] of int64;
	f,f1: Text;
function kt():boolean;
var
tam,xau:string;
so:int64;
begin      xau:='';    tam:='';
 for j:=1 to n do
  begin
   str(s[x[j]],tam);
   xau:=xau+tam;
  end;
 val(xau,so,u); if so mod 11=0 then exit(true)else exit(false);
end;
procedure Swap(var X, Y: Int64);
var
	Temp: Int64;
begin
	Temp := X; X := Y; Y := Temp;
end;

begin
	Assign(f,fi); Reset(f);
        assign(f1,fo); rewrite(f1);
        readln(f,q);
	for l:=1 to q do
         begin
          Readln(f, n);
          for i:=1 to n do  read(f,s[i]);
	 for i := 1 to n do x[i] := i;
         res:=0;
	repeat
		if kt() then inc(res);
		i := n - 1;
		while (i > 0) and (x[i] > x[i + 1]) do Dec(i);
		if i > 0 then
		begin
			k := n;
			while x[k] < x[i] do Dec(k);
			Swap(x[k], x[i]);
			a := i + 1; b := n;
			while a < b do
			begin
				Swap(x[a], x[b]);
				Inc(a);
				Dec(b);
			end;
		end;
	until i = 0;
        writeln(f1,res);
        end;
        close(F1);













	Close(f);
end.
