package br.unisal.gui;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import java.util.EnumSet;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

import br.unisal.jdbc.DispositivoDAO;
import br.unisal.modelagem.Dispositivo;
import br.unisal.modelagem.Tipo;

public class frmCadDispositivo extends JFrame
					implements ActionListener{	
	//1º Passo - Declarar os objetos visuais
	JLabel lbTipo, lbDescricao, lbTag, lbMaximo,
		   lbMinimo, lbSetPoint, lbEstado, lbSinal;
	JTextField txtDescricao, txtTag, txtMaximo,
			   txtMinimo, txtSetPoint;
	JComboBox<String> cbxTipo, cbxEstado, cbxSinal;
	JButton btCadastrar, btFechar;
	JPanel pnCampos, pnBotoes;
	DispositivoDAO dao;

	public frmCadDispositivo() {
		super("Cadastro de Dispositivos");
		setSize(300, 300);
		setLayout(new BorderLayout());
		dao = new DispositivoDAO();
		
		//2º Passo - Instanciar os objetos gráficos
		lbTipo = new JLabel("Tipo");
		lbDescricao = new JLabel("Descrição");
		lbTag = new JLabel("TAG");
		lbMaximo = new JLabel("Máximo");
		lbMinimo = new JLabel("Minímo");
		lbSetPoint = new JLabel("SetPoint");
		lbEstado = new JLabel("Estado");
		lbSinal = new JLabel("Sinal");
		txtDescricao = new JTextField();
		txtMaximo = new JTextField();
		txtMinimo = new JTextField();
		txtTag = new JTextField();
		txtSetPoint = new JTextField();
		
		String valores[] = new String[2];
		int i = 0;
		for (Tipo t : EnumSet.allOf(Tipo.class)){
			valores[i++] = t.getDescricao();
		}
		cbxTipo = new JComboBox<String>(valores);
		
		String opcoes[] = {"Ativo", "Inativo"};
		cbxEstado = new JComboBox<String>(opcoes);
		
		String sinais[] = {"Digital", "Analógico"};
		cbxSinal = new JComboBox<String>(sinais);
		
		btCadastrar = new JButton("Cadastrar");
		btFechar = new JButton("Fechar");
		
		btCadastrar.addActionListener(this);
		btFechar.addActionListener(this);
		
		pnCampos = new JPanel(new GridLayout(8,2));
		pnBotoes = new JPanel(new GridLayout(1,2));
		
		pnCampos.add(lbTipo);
		pnCampos.add(cbxTipo);
		pnCampos.add(lbDescricao);
		pnCampos.add(txtDescricao);
		pnCampos.add(lbTag);
		pnCampos.add(txtTag);
		pnCampos.add(lbMinimo);
		pnCampos.add(txtMinimo);
		pnCampos.add(lbMaximo);
		pnCampos.add(txtMaximo);
		pnCampos.add(lbSetPoint);
		pnCampos.add(txtSetPoint);
		pnCampos.add(lbEstado);
		pnCampos.add(cbxEstado);
		pnCampos.add(lbSinal);
		pnCampos.add(cbxSinal);
		
		pnBotoes.add(btCadastrar);
		pnBotoes.add(btFechar);
		
		add(pnCampos, BorderLayout.CENTER);
		add(pnBotoes, BorderLayout.SOUTH);
		setVisible(true);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == btCadastrar) {
			try {
				dao.inserir(instanciarObjeto());
				JOptionPane.showMessageDialog(null, 
						"Persistência Realizada com Sucesso.");
			} catch (SQLException e1) {
				e1.printStackTrace();
				JOptionPane.showMessageDialog(null, 
						"Erro ao Salvar",
						"Falha na Persistência", 
						JOptionPane.ERROR_MESSAGE);
			}
		}else {
			System.exit(0);
		}
	}
	
	private Dispositivo instanciarObjeto() {
		Dispositivo d = new Dispositivo();
		d.setTipo(Tipo.values()[cbxTipo.getSelectedIndex()]);
		d.setDescricao(txtDescricao.getText());
		d.setMaximo(Double.parseDouble(txtMaximo.getText()));
		d.setMinimo(Double.parseDouble(txtMinimo.getText()));
		d.setSetPoint(Double.parseDouble(txtSetPoint.getText()));
		d.setEstado(cbxEstado.getSelectedIndex() == 0);
		d.setTag(Integer.parseInt(txtTag.getText()));
		d.setSinal(cbxSinal.getSelectedIndex() == 0 ? 'D' : 'A');
		
		return d;
	}

	public static void main(String[] args) {
		frmCadDispositivo frm = new frmCadDispositivo();
		frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
