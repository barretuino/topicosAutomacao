package br.puc.ibarreto.jdbc;
/**
 * Projeto de Ger?ncia
 * Classe DAO - Data Access Object
 * @autor Paulo C. Barreto / Luiz R. Barreto
 * @date 26/05/2012
 */

import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Time;
import java.util.GregorianCalendar;

import br.puc.ibarreto.modelagem.Medida;

public class MedicaoDAO {
	//Estabele conex?o com o banco de dados
	private Connection connection;
	public MedicaoDAO() throws SQLException {
		this.connection = ConnectionFactory.getConnection();
	}
	public void adiciona(Medida leitura) throws SQLException {
		//Prepara statement para inser??o
		PreparedStatement stmt = this.connection.prepareStatement("insert into consumo (data, hora, valor) values (?, ?, ?)");
		
		//Seta os valores dos argumentos da stmt	
		GregorianCalendar atual = new GregorianCalendar();
		Date data = new Date(atual.getTime().getYear(), atual.getTime().getMonth(), atual.getTime().getDate());
		Time hora = new Time(atual.getTime().getHours(), atual.getTime().getMinutes(), atual.getTime().getSeconds());
		
		stmt.setDate(1, data);
		stmt.setTime(2, hora);
		stmt.setFloat(3,(float) leitura.getValor());
		
		//Executa query
		stmt.execute();
		stmt.close();
	}
}