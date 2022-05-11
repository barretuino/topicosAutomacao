package br.unisal.jdbc;
/**
 * Projeto de Gerência
 * ConnectionFactory - Fábrica de Conexões com o Banco
 * @autor Paulo C. Barreto
 * @date 20/04/2022
 */

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionFactory {
	public static Connection getConnection() throws SQLException {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			return DriverManager.getConnection("jdbc:mysql://192.168.40.41/unisal",
					"paulo","12345679");
		} catch (ClassNotFoundException e) {
			throw new SQLException(e.getMessage());
		}
	}
	
	public static void main(String[] args) {
		try {
			ConnectionFactory.getConnection();
			System.out.println("Conexão realizada com sucesso.");
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
}