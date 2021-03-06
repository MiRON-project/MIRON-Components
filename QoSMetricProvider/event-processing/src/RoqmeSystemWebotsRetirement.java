import org.roqme.cep.PatternDetector;
import Roqme.RoqmeDDSException;

public class RoqmeSystemWebotsRetirement {

	public static void main(String[] args) throws RoqmeDDSException, InterruptedException {
		RoqmeSystemWebotsRetirement exec = new RoqmeSystemWebotsRetirement();
		PatternDetector pd=null;
		
		try{
			pd = new PatternDetector();
			pd.launch("RoqmeSystemWebotsRetirement.epl");
			synchronized (exec) {
				exec.wait();
			}
		} catch(Exception e){
			e.printStackTrace();
		} finally {
			pd.destroy();
		}
	}
}
