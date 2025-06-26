function alterarCorTabela() {
  document.getElementById("tabela").classList.toggle("table-dark");
}
function ordenarLista(crescente) {
  const lista = document.getElementById("listaTreinos");
  const itens = Array.from(lista.children).map(li => li.textContent);
  itens.sort();
  if (!crescente) itens.reverse();
  lista.innerHTML = "";
  itens.forEach(txt => {
    const li = document.createElement("li");
    li.textContent = txt;
    lista.appendChild(li);
  });
}
function validarFormulario() {
  const nome = document.getElementById("nome").value;
  const email = document.getElementById("email").value;
  const plano = document.getElementById("plano").value;
  const termos = document.getElementById("termos").checked;
  if (!nome || !email || !plano || !termos) {
    alert("Por favor, preencha todos os campos e aceite os termos.");
    return false;
  }
  alert("Cadastro realizado com Sucesso");
  return true;
}
function calcular(op) {
  const n1 = parseFloat(document.getElementById("n1").value);
  const n2 = parseFloat(document.getElementById("n2").value);
  let res = 0;
  if (isNaN(n1) || isNaN(n2)) return alert("Informe dois números válidos.");
  switch (op) {
    case "soma": res = n1 + n2; break;
    case "subtracao": res = n1 - n2; break;
    case "multiplicacao": res = n1 * n2; break;
    case "divisao": res = n2 !== 0 ? n1 / n2 : "Erro: divisão por zero"; break;
    case "potencia": res = Math.pow(n1, n2); break;
    case "raiz": res = `√${n1}=${Math.sqrt(n1).toFixed(2)} | √${n2}=${Math.sqrt(n2).toFixed(2)}`; break;
  }
  document.getElementById("resultado").innerText = res;
}