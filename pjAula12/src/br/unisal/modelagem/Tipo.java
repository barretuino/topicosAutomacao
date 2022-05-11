package br.unisal.modelagem;

public enum Tipo {
	ATUADOR(1, "Atuador"),
	SENSOR(2, "Sensor");

	private int id;
	private String descricao;
	
	Tipo(int id, String descricao) {
		this.setId(id);
		this.descricao = descricao;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}
	
	
}
