const nhap = 'BONUS.INP';
      xuat = 'BONUS.OUT';
type mang = array [1..1000, 1..1000] of longint;
var f: text;
    n, k, i ,j, r, dem, ketqua, h: word;
    a: mang;
    x, y: array[1..1000] of longint;
procedure input;
var f: text;
  begin
        assign(f, nhap);
        reset(f);
        read(f, n, r, k);
        for i := 1 to n do
          for j := 1 to n do
                read(f, a[i, j]);
        for h := 1 to k do
                read(f, x[h], y[h]);
        close(f);
  end;

procedure solve;
var f: text;
  begin
        assign(f, xuat);
        rewrite(f);
        dem := 0;
        ketqua := 0;
        for h := 1 to k do
                if ((x[h] > r) and (y[h] > r)) then dem:= dem +1;
        ketqua := r * r * k - (k - dem);
        write(f, ketqua);
        close(f);
  end;

begin
        input;
        solve;
end.
