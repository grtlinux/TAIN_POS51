/**
 * Copyright 2014, 2015, 2016 TAIN, Inc. all rights reserved.
 *
 * Licensed under the GNU GENERAL PUBLIC LICENSE, Version 3, 29 June 2007 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.gnu.org/licenses/
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * -----------------------------------------------------------------
 * Copyright 2014, 2015, 2016 TAIN, Inc.
 *
 */
package tain.kr.com.proj.pos51.v02.tools;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FilenameFilter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ResourceBundle;

import org.apache.log4j.Logger;

import tain.kr.com.proj.pos51.v02.util.DateTime;
import tain.kr.com.proj.pos51.v02.util.RecvFQ;

/**
 * Code Templates > Comments > Types
 *
 * <PRE>
 *   -. FileName   : ReceiveResult02.java
 *   -. Package    : tain.kr.com.proj.pos51.v02.tools
 *   -. Comment    :
 *   -. Author     : taincokr
 *   -. First Date : 2016. 3. 22. {time}
 * </PRE>
 *
 * @author taincokr
 *
 */
public class ReceiveResult02 extends Thread {

	private static boolean flag = true;

	private static final Logger log = Logger.getLogger(ReceiveResult02.class);

	///////////////////////////////////////////////////////////////////////////////////////////////
	
	private static final String THREAD_NAME = "RECEIVE_RESULT_02";
	
	private String clsName = null;
	
	private String strDescription = null;

	private String strInFileCharset = null;
	private String strInFilePath = null;
	private String strInFileName = null;

	private String strMvFilePath = null;
	private String strMvFileName = null;
	
	private String strOutFileCharset = null;
	private String strOutFilePath = null;
	private String strOutFileName = null;

	private String strFqFilePatn = null;
	private String strFqFileName = null;
	
	public ReceiveResult02() throws Exception {
		
		super(THREAD_NAME);
		
		if (flag) {
			this.clsName = this.getClass().getName();
			
			ResourceBundle rb = ResourceBundle.getBundle(this.clsName.replace('.','/'));
			
			this.strDescription    = rb.getString("tain.pos51.02.receive.result.desc" );

			this.strInFileCharset  = rb.getString("tain.pos51.02.recv.in.file.charset" );
			this.strInFilePath     = rb.getString("tain.pos51.02.recv.in.file.path"    );
			this.strInFileName     = rb.getString("tain.pos51.02.recv.in.file.name"    );

			this.strMvFilePath     = rb.getString("tain.pos51.02.recv.mv.file.path"    );

			this.strOutFileCharset = rb.getString("tain.pos51.02.recv.out.file.charset");
			this.strOutFilePath    = rb.getString("tain.pos51.02.recv.out.file.path"   );
			this.strOutFileName    = rb.getString("tain.pos51.02.recv.out.file.name"   );

			this.strFqFilePatn     = rb.getString("tain.pos51.02.recv.fq.file.path"    );
			this.strFqFileName     = rb.getString("tain.pos51.02.recv.fq.file.name"    );
		}

		if (flag) {
			/*
			 * System.properties
			 */
			this.strDescription    = System.getProperty("tain.pos51.02.receive.result.desc" , this.strDescription   );

			this.strInFileCharset  = System.getProperty("tain.pos51.02.recv.in.file.charset" , this.strInFileCharset );
			this.strInFilePath     = System.getProperty("tain.pos51.02.recv.in.file.path"    , this.strInFilePath    );
			this.strInFileName     = System.getProperty("tain.pos51.02.recv.in.file.name"    , this.strInFileName    );

			this.strMvFilePath     = System.getProperty("tain.pos51.02.recv.mv.file.path"    , this.strMvFilePath    );

			this.strOutFileCharset = System.getProperty("tain.pos51.02.recv.out.file.charset", this.strOutFileCharset);
			this.strOutFilePath    = System.getProperty("tain.pos51.02.recv.out.file.path"   , this.strOutFilePath   );
			this.strOutFileName    = System.getProperty("tain.pos51.02.recv.out.file.name"   , this.strOutFileName   );

			this.strFqFilePatn     = System.getProperty("tain.pos51.02.recv.fq.file.path"    , this.strFqFilePatn    );
			this.strFqFileName     = System.getProperty("tain.pos51.02.recv.fq.file.name"    , this.strFqFileName    );
		}

		if (flag) {
			/*
			 * change parameters
			 */
			this.strInFileName  = this.strInFilePath + File.separator + this.strInFileName;
			//this.strInFileName  = this.strInFileName.replaceAll("YYYYMMDDHHMMSS", DateTime.getInstance().getYYYYMMDDHHMMSS());

			this.strOutFilePath = this.strOutFilePath.replaceAll("YYYYMMDD", DateTime.getInstance().getYYYYMMDD());
			this.strOutFileName = this.strOutFilePath + File.separator + this.strOutFileName;
			//this.strOutFileName = this.strOutFileName.replaceAll("YYYYMMDD", DateTime.getInstance().getYYYYMMDD());

			this.strFqFileName  = this.strFqFilePatn + File.separator + this.strFqFileName;
			this.strFqFileName  = this.strFqFileName.replaceAll("YYYYMMDD", DateTime.getInstance().getYYYYMMDD());
		}

		if (flag) {
			log.debug("+------------------------------------------------------------------------------------+");
			log.debug("|                                                                                    |");
			log.debug("|      02. ReceiveResult02 : 02.접수결과 : R_POS_POSHW000002                         |");
			log.debug("|                                                                                    |");
			log.debug("+------------------------------------------------------------------------------------+");
			log.debug("FQ  FILE : " + this.strFqFileName);
			log.debug("IN  FILE : " + this.strInFileName);
			log.debug("OUT FILE : " + this.strOutFileName);
		}
	}
	
	public void run() {
		
		if (flag) {
			/*
			 * if the file FQ is not exist, then this module's going to end...
			 */
			File file = new File(this.strFqFileName);
			if (!file.exists()) {
				if (flag) log.error("ERROR : the file doesn't exist..[" + this.strFqFileName + "]");
				return;
			}
		}

		if (flag) {
			
			try {
				for (int i=0; i < 1; i++) {
					
					if (!transferFile())
						break;
				}
			} catch (Exception e) {
				//
				e.printStackTrace();
			} finally {
				// wait some seconds
				try { Thread.sleep(1000); } catch (InterruptedException e) {}
			}
		}
	}
	
	/*
	 * FQ : recv
	 */
	
	private RecvFQ recvFQ = null;
	
	private String strDate = null;
	
	private String strRecSeq = null;
	
	private int recCnt = -1;
	
	private boolean transferFile() throws Exception {
		
		if (flag) {
			/*
			 * read files
			 */
			
			// execute root directory
			File path = new File(this.strInFilePath);
			
			// return list of files
			String[] files = path.list(new FilenameFilter() {
				@Override
				public boolean accept(File dir, String name) {
					
					int lastIndex = name.lastIndexOf("recv_");
					if (lastIndex < 0)
						return false;
					
					return true;
				}
			});
			
			if (files.length == 0) {
				/*
				 * if there is no list, then return false.
				 */
				return false;
			}

			String firstFile = "zzz";
			
			if (flag) {
				/*
				 * select first file.
				 */
				for (String file : files) {
					
					if (!flag) log.debug(String.format("[%s]  [%s]", firstFile, file));
					
					if (file.compareTo(firstFile) < 0) {
						firstFile = file;
					}
				}
			}
			
			if (flag) {
				
				this.strInFileName = this.strInFilePath + File.separator + firstFile;
				this.strMvFileName = this.strMvFilePath + File.separator + firstFile;
				
				this.strDate = firstFile.substring(5, 13);
				
				if (flag) log.debug("IN FILE [" + this.strInFileName + "]");
				if (flag) log.debug("Mv FILE [" + this.strMvFileName + "]");
				if (flag) log.debug("DATE    [" + this.strDate + "]");
			}
		}
		
		if (flag) {
			/*
			 * get the FQ sequence
			 */
			this.recvFQ = new RecvFQ(this.strFqFileName, this.strInFileName, recCnt);
			
			this.strRecSeq = this.recvFQ.getRecSeq();
			
			this.recvFQ.close();
			
			this.recvFQ = null;
		}
		
		if (flag) {
			/*
			 * transfer file from IN to OUT
			 */
			BufferedReader reader = null;
			PrintWriter writer = null;

			try {

				// in file
				File inFile = new File(this.strInFileName);
				FileInputStream inFileStream = new FileInputStream(inFile);
				reader = new BufferedReader(new InputStreamReader(inFileStream, this.strInFileCharset));

				// out file
				this.strOutFileName = this.strOutFileName.replaceAll("YYYYMMDD", this.strDate);
				this.strOutFileName = this.strOutFileName.replaceAll("SEQ", this.strRecSeq);
				
				File outFile = new File(this.strOutFileName);
				FileOutputStream outFileStream = new FileOutputStream(outFile);
				OutputStreamWriter outWriter = new OutputStreamWriter(outFileStream, this.strOutFileCharset);
				writer = new PrintWriter(outWriter);

				String line = null;

				this.recCnt = 0;
				
				while ((line = reader.readLine()) != null) {
					if (flag) log.debug("[" + line + "]");

					writer.println(line);
					++ this.recCnt;
				}
			} catch (Exception e) {
				//
				throw e;
			} finally {
				if (reader != null) try { reader.close(); } catch (Exception e) {}
				if (writer != null) try { writer.close(); } catch (Exception e) {}
			}
		}
		
		if (flag) {
			/*
			 * write a record in FQ
			 */
			this.recvFQ = new RecvFQ(this.strFqFileName, this.strInFileName, recCnt);
			
			if (flag) this.recvFQ.readAll();
			
			if (flag) this.recvFQ.write();
			
			this.recvFQ.close();
			
			this.recvFQ = null;
		}
		
		if (flag) {
			/*
			 * move file from receive folder to received folder
			 */
			new File(this.strInFileName).renameTo(new File(this.strMvFileName));
		}
		
		return true;
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////

	private static void test01(String[] args) throws Exception {
		
		if (flag) {
			Thread thr = new ReceiveResult02();
			thr.start();
			thr.join();
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		if (flag) log.debug(">>>>> " + new Object(){}.getClass().getEnclosingClass().getName());
		
		if (flag) test01(args);
	}
}
