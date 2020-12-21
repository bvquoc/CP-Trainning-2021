program Shortest_Path_by_Dijkstra_and_Heap;
const
   InputFile = 'DHAKA.INP';
   OutputFile = 'DHAKA.OUT';
   max = 10000;
   maxE = 100000;
   maxEC = 100000;
   maxC = max * maxEC;
type
   TAdj = array[0..maxE] of longint;
   TAdjCost = array[0..maxE] of longint;
   THeader = array[0..max + 1] of longint;
var
   adj: TAdj; {Danh sách kề dạng mảng}
   adjCost: TAdjCost; {Kèm trọng số}
   h: THeader; {Mảng đánh dấu các đoạn trong danh sách kề adj}
   d: array[0..max] of longint;
   Trace: array[0..max] of longint;
   Free: array[0..max] of Boolean;
   heap: array[0..max] of longint; {heap[i] = đỉnh lưu tại nút i của heap}
   Pos: array[0..max] of longint; {pos[v] = vị trí của nút v trong heap (tức là    pos[heap[i]] = i)}
   n, s, f,l,k, nHeap: longint;
   xau:string;
procedure LoadGraph; {Nhập dữ liệu}
var
   i, m, u, v, c: Integer;
   fi: Text;
begin
   Assign(fi, InputFile); Reset(fi);
   ReadLn(fi, n, m, l,k);
   s:=1;
   f:=n;
   for i:=1 to n do readln(fi,xau);

   FillChar(h, SizeOf(h), 0);
   for i := 1 to m do
   begin
      Inc(h[i]);
   end;
   for i := 2 to n do h[i] := h[i - 1] + h[i]; {Bỏ qua dòng đầu tiên Input file}
   for i := 1 to m do
      begin
         ReadLn(fi, u, v, c);
         adj[h[u]] := v; {Điền v và c vào vị trí đúng trong danh sách kề của u}
         adjCost[h[u]] := c;
         Dec(h[u]);
      end;
   h[n + 1] := m;
   Close(fi);
end;

procedure Init; {Khởi tạo d[i] = độ dài đường đi ngắn nhất từ s tới i qua 0 cạnh, Heap rỗng}
var
   i: Integer;
begin
   for i := 1 to n do d[i] := maxC;
   d[s] := 0;
   FillChar(Free, SizeOf(Free), True);
   FillChar(Pos, SizeOf(Pos), 0);
   nHeap := 0;
end;

procedure Update(v: Integer); {Đỉnh v vừa được sửa nhãn, cần phải chỉnh lại Heap}
var
   parent, child: Integer;
begin
   child := Pos[v];
      if child = 0 then
      begin
         Inc(nHeap); child := nHeap;
      end;
   parent := child div 2; {parent là nút cha của child}
   while (parent > 0) and (d[heap[parent]] > d[v]) do
      begin
         heap[child] := heap[parent]; {Đẩy đỉnh lưu trong nút cha xuống nút con}
         Pos[heap[child]] := child; {Ghi nhận lại vị trí mới của đỉnh đó}
         child := parent; {Tiếp tục xét lên phía nút gốc}
         parent := child div 2;
      end;
   heap[child] := v;
   Pos[v] := child;
end;


function Pop: Integer; {Lấy từ Heap ra đỉnh có nhãn tự do nhỏ nhất}
var
   r, c, v: Integer;
begin
   Pop := heap[1]; {Nút gốc Heap chứa đỉnh có nhãn tự do nhỏ nhất}
   v := heap[nHeap]; {v là đỉnh ở nút lá cuồi Heap, sẽ được đảo lên đầu và vun đống}
   Dec(nHeap);
   r := 1; {Bắt đầu từ nút gốc}
   while r * 2 <= nHeap do
      begin
         c := r * 2;
         if (c < nHeap) and (d[heap[c + 1]] < d[heap[c]]) then Inc(c);
         if d[v] <= d[heap[c]] then Break;
         heap[r] := heap[c]; {Chuyển đỉnh lưu ở nút con c lên nút cha r}
         Pos[heap[r]] := r; {Ghi nhận lại vị trí mới trong Heap của đỉnh đó}
         r := c; {Gán nút cha := nút con và lặp lại}
      end;
   heap[r] := v; {Đỉnh v sẽ được đặt vào nút r để bảo toàn cấu trúc Heap}
   Pos[v] := r;
end;


procedure Dijkstra;
var
   i, u, iv, v, min: Integer;
begin
   Update(s); {Đưa đỉnh xuất phát về gốc Heap}
   repeat
   u := Pop; {Chọn đỉnh tự do có nhãn nhỏ nhất}
   if u = f then Break; {Nếu đỉnh đó là f thì dừng ngay}
   Free[u] := False; {Cố định nhãn đỉnh đó}
   for iv := h[u] + 1 to h[u + 1] do {Xét danh sách kề}
      begin
         v := adj[iv];
         if Free[v] and (d[v] > d[u] + adjCost[iv]) then
            begin
               d[v] := d[u] + adjCost[iv]; {Tối ưu hoá nhãn của các đỉnh tự do kề với u}
               Trace[v] := u; {Lưu vết đường đi}
               Update(v); {Tổ chức lại Heap}
            end;
      end;
   until nHeap = 0; {Không còn đỉnh nào mang nhãn tự do}
end;

procedure PrintResult;
var
   fo: Text;
begin
   Assign(fo, OutputFile); Rewrite(fo);
   if d[f] = maxC then
   WriteLn(fo,-1)
   else
      begin
         WriteLn(fo,d[f]);
      end;
   Close(fo);
end;

begin
   LoadGraph;
   Init;
   Dijkstra;
   PrintResult;
end.
