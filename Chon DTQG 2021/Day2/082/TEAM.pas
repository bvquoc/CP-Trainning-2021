const nhap = 'TEAM.INP';
      xuat = 'TEAM.OUT';
type mang = array[0..10000] of int64;
var f: text;
    n, i: longint;
    k: int64;
    a: mang;
procedure input;
var f: text;
  begin
        assign(f, nhap);
        reset(f);
        read(f, n, k);
        for i := 0 to n - 1 do
                read(f, a[i]);
        close(f);
  end;

procedure solve;
var f: text;
  begin
        assign(f, xuat);
        rewrite(f);
        i:= 0;
        while (k - a[i] >= 0) do
          begin
                k := k - a[i];
                inc(i);
                if ((i = n - 1) and (k - a[i] >= 0)) then
                  begin
                        k := k - a[i];
                        i := 0;
                  end;
          end;
        write(f, k);
        close(f);
  end;

begin
        input;
        solve;
end.
