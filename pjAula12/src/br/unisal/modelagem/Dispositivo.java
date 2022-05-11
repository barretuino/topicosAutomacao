package br.unisal.modelagem;

public class Dispositivo {
	private Tipo tipo;
	private String descricao;
	private double minimo;
	private double maximo;
	private boolean estado;
	private double setPoint;
	private int tag;
	private char sinal;
	
	public Dispositivo() {
		
	}
	
	public Dispositivo(Tipo tipo, String descricao, 
			double minimo, double maximo, 
			boolean estado, double setPoint,
			int tag, char sinal) {
		super();
		this.tipo = tipo;
		this.descricao = descricao;
		this.minimo = minimo;
		this.maximo = maximo;
		this.estado = estado;
		this.setPoint = setPoint;
		this.tag = tag;
		this.sinal = sinal;
	}
	public Tipo getTipo() {
		return tipo;
	}
	public void setTipo(Tipo tipo) {
		this.tipo = tipo;
	}
	public String getDescricao() {
		return descricao;
	}
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public double getMinimo() {
		return minimo;
	}

	public void setMinimo(double minimo) {
		this.minimo = minimo;
	}

	public double getMaximo() {
		return maximo;
	}

	public void setMaximo(double maximo) {
		this.maximo = maximo;
	}
	public boolean isEstado() {
		return estado;
	}
	public void setEstado(boolean estado) {
		this.estado = estado;
	}
	public double getSetPoint() {
		return setPoint;
	}
	public void setSetPoint(double setPoint) {
		this.setPoint = setPoint;
	}
	public int getTag() {
		return tag;
	}
	public void setTag(int tag) {
		this.tag = tag;
	}

	public char getSinal() {
		return sinal;
	}

	public void setSinal(char sinal) {
		this.sinal = sinal;
	}
	
	
}
