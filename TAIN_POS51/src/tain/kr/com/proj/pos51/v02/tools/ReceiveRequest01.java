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

import java.io.File;
import java.util.ResourceBundle;

import org.apache.log4j.Logger;

import tain.kr.com.proj.pos51.v02.util.DateTime;

/**
 * Code Templates > Comments > Types
 *
 * <PRE>
 *   -. FileName   : ReceiveRequest01.java
 *   -. Package    : tain.kr.com.proj.pos51.v02.main
 *   -. Comment    :
 *   -. Author     : taincokr
 *   -. First Date : 2016. 3. 22. {time}
 * </PRE>
 *
 * @author taincokr
 *
 */
public class ReceiveRequest01 extends Thread {

	private static boolean flag = true;

	private static final Logger log = Logger.getLogger(ReceiveRequest01.class);

	///////////////////////////////////////////////////////////////////////////////////////////////
	
	private static final String THREAD_NAME = "RECEIVE_REQUEST_01";
	
	private String clsName = null;
	
	private String strDescription = null;
	
	private String strInFileCharset = null;
	private String strInFilePath = null;
	private String strInFileName = null;
	
	private String strOutFileCharset = null;
	private String strOutFilePath = null;
	private String strOutFileName = null;
	
	private String strFqFilePatn = null;
	private String strFqFileName = null;
	
	public ReceiveRequest01() throws Exception {
		
		super(THREAD_NAME);
		
		if (flag) {
			/*
			 * ResourceBundle
			 */
			this.clsName = this.getClass().getName();
			
			ResourceBundle rb = ResourceBundle.getBundle(this.clsName.replace('.', '/'));
			
			this.strDescription    = rb.getString("tain.pos51.01.receive.request.desc" );

			this.strInFileCharset  = rb.getString("tain.pos51.01.send.in.file.charset" );
			this.strInFilePath     = rb.getString("tain.pos51.01.send.in.file.path"    );
			this.strInFileName     = rb.getString("tain.pos51.01.send.in.file.name"    );
			
			this.strOutFileCharset = rb.getString("tain.pos51.01.send.out.file.charset");
			this.strOutFilePath    = rb.getString("tain.pos51.01.send.out.file.path"   );
			this.strOutFileName    = rb.getString("tain.pos51.01.send.out.file.name"   );
			
			this.strFqFilePatn     = rb.getString("tain.pos51.01.send.fq.file.path"    );
			this.strFqFileName     = rb.getString("tain.pos51.01.send.fq.file.name"    );
		}
		
		if (flag) {
			/*
			 * System.properties
			 */
			this.strDescription    = System.getProperty("tain.pos51.01.receive.request.desc" , this.strDescription   );

			this.strInFileCharset  = System.getProperty("tain.pos51.01.send.in.file.charset" , this.strInFileCharset );
			this.strInFilePath     = System.getProperty("tain.pos51.01.send.in.file.path"    , this.strInFilePath    );
			this.strInFileName     = System.getProperty("tain.pos51.01.send.in.file.name"    , this.strInFileName    );
			
			this.strOutFileCharset = System.getProperty("tain.pos51.01.send.out.file.charset", this.strOutFileCharset);
			this.strOutFilePath    = System.getProperty("tain.pos51.01.send.out.file.path"   , this.strOutFilePath   );
			this.strOutFileName    = System.getProperty("tain.pos51.01.send.out.file.name"   , this.strOutFileName   );
			
			this.strFqFilePatn     = System.getProperty("tain.pos51.01.send.fq.file.path"    , this.strFqFilePatn    );
			this.strFqFileName     = System.getProperty("tain.pos51.01.send.fq.file.name"    , this.strFqFileName    );
		}
		
		if (flag) {
			/*
			 * change parameters
			 */
			this.strInFileName  = this.strInFilePath + File.separator + this.strInFileName;
			this.strInFileName  = this.strInFileName.replaceAll("YYYYMMDD", DateTime.getInstance().getYYYYMMDD());
			
			this.strOutFileName = this.strOutFilePath + File.separator + this.strOutFileName;
			this.strOutFileName = this.strOutFileName.replaceAll("YYYYMMDDHHMMSS", DateTime.getInstance().getYYYYMMDDHHMMSS());
			
			this.strFqFileName  = this.strFqFilePatn + File.separator + this.strFqFileName;
			this.strFqFileName  = this.strFqFileName.replaceAll("YYYYMMDD", DateTime.getInstance().getYYYYMMDD());
		}
		
		if (flag) {
			log.debug("FQ  FILE : " + this.strFqFileName);
			log.debug("IN  FILE : " + this.strInFileName);
			log.debug("OUT FILE : " + this.strOutFileName);
		}
	}
	
	public void run() {
		
		if (flag) {
			/*
			 * read FQ
			 */
			
			try {
				
			} catch (Exception e) {
				//
				e.printStackTrace();
			} finally {
				
			}
		}
		
		if (flag) {
			/*
			 * transfer file from IN to OUT
			 */
			
			try {
				
			} catch (Exception e) {
				//
				e.printStackTrace();
			} finally {
				
			}
		}
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////

	private static void test01(String[] args) throws Exception {
		
		if (flag) {
			Thread thr = new ReceiveRequest01();
			thr.start();
			thr.join();
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		if (flag) log.debug(">>>>> " + new Object(){}.getClass().getEnclosingClass().getName());
		
		if (flag) test01(args);
	}
}
