package br.puc.ibarreto.modelagem;
/**
 * Projeto de Gerência
 * Modelagem Conceitual de Medida
 * @autor Paulo C. Barreto / Luiz R. Barreto
 * @date 26/05/2012
 */

import java.util.GregorianCalendar;


public class Medida {
	private float valor;
	private GregorianCalendar data;
	
	public Medida(){
		
	}

	public float getValor() {
		return valor;
	}

	public void setValor(float valor) {
		this.valor = valor;
	}

	public GregorianCalendar getData() {
		return data;
	}

	public void setData(GregorianCalendar data) {
		this.data = data;
	}
}
