package br.unisal.jdbc;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import br.unisal.modelagem.Dispositivo;

public class DispositivoDAO {
	Connection con;
	public DispositivoDAO() {
		try {
			con = ConnectionFactory.getConnection();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public void inserir(Dispositivo dispositivo) throws SQLException {
		//Prepara statement para inserção
		PreparedStatement stmt = 
				this.con.prepareStatement(
				  "insert into dispositivos "
				  + "(tipo, descricao, maximo, minimo,"
				  + "tag, setPoint, estado, sinal) "
				  + "values (?, ?, ?, ?, ?, ?, ?, ?)");
		
		stmt.setInt(1, dispositivo.getTipo().getId());
		stmt.setString(2, dispositivo.getDescricao());
		stmt.setDouble(3, dispositivo.getMaximo());
		stmt.setDouble(4, dispositivo.getMinimo());
		stmt.setInt(5, dispositivo.getTag());
		stmt.setDouble(6, dispositivo.getSetPoint());
		stmt.setString(7, dispositivo.isEstado() ? "T" : "F");
		stmt.setString(8, dispositivo.getSinal() + "");
		
		stmt.execute();
	}
}
